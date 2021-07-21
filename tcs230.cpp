#include "tsc230.h"
//#include "tsc230.hpp"
#include "Arduino.h"


TSC_230::TSC_230(int s0, int s1, int s2, int s3, int out):
    s0(s0),
    s1(s1),
    s2(s2),
    s3(s3),
    out(out)
{}


void TSC_230::setup(){
    pinMode(s0, OUTPUT);    
    pinMode(s1, OUTPUT);
    pinMode(s2, OUTPUT);
    pinMode(s3, OUTPUT);
    pinMode(out, INPUT);
    set_freq_scale(twenty);
    set_calibration_auto();
}

// set calibration to auto or manual
void TSC_230::set_calibration_manual(TSC_230_calibration c) {
    manual_calibration = true;
}

void TSC_230::set_calibration_auto() {
    color scheme[3] = {red, green, blue};
    for (auto c : scheme) {// when auto calibrating we need to set minimums and maximums as range, we will dynamicly set those, till now we set it to max val of 1000
        cur_cal.base.set(c, 1000);
        cur_cal.ceil.set(c, 0);
    } manual_calibration = false;
}

// read raw sensor data
int TSC_230::read_color(color in) {
    switch(in){
        case red:
            digitalWrite(s2, LOW);
            digitalWrite(s3, LOW);
            break;
        case green:
            digitalWrite(s2, HIGH);
            digitalWrite(s3, HIGH);
            break;
        case blue:
            digitalWrite(s2, LOW);
            digitalWrite(s3, HIGH);
            break;
    }
    int color_freq = pulseIn(out, LOW);
    delay(100);
    return color_freq;
}

int TSC_230::pw_to_rgb(color in, int pw) {
    // set new ceiling or baseline if we doing auto calibrating
    if (!manual_calibration) {
        if (cur_cal.base.get(in) > pw)
            cur_cal.base.set(in, pw);
        if (cur_cal.ceil.get(in) < pw)
            cur_cal.ceil.set(in, pw);
    }
    int converted_val = map(pw ,cur_cal.base.get(in) ,cur_cal.ceil.get(in), 255, 0);
    return converted_val;
}

void TSC_230::set_freq_scale(frequencies in) {
    // set freq state so we can keep track of the frequency
    freq = in;
    switch (in) {
        case zero:
            digitalWrite(s0, LOW);
            digitalWrite(s1, LOW);
            break;
        case two:
            digitalWrite(s0, LOW);
            digitalWrite(s1, HIGH);
            break;
        case twenty:
            digitalWrite(s0, HIGH);
            digitalWrite(s1, LOW);
            break;
        case hundred:
            digitalWrite(s0, HIGH);
            digitalWrite(s1, HIGH);
            break;
    }
}

RGB TSC_230::read_rgb() {
    color scheme[3] = {red, green, blue};
    RGB new_val;
    for (auto c : scheme) {
        int raw_val = read_color(c);
        int rgb_color = pw_to_rgb(c, raw_val);
        new_val.set(c, rgb_color);
    } return new_val;
}

void TSC_230::calibrate_in_seconds(int seconds) {
    if (manual_calibration)
        set_calibration_auto();
    seconds /= 3;
    color scheme[3] = {red, green, blue};
    for (int i = 0; i < seconds/3; i ++)
        read_rgb();
}