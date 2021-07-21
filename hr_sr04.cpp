#include "hr_sr04.h"

HR_SR04::HR_SR04(const int t_pin,const int e_pin) {
    echo_pin = e_pin;
    trig_pin = t_pin;
    pinMode(trig_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
    digitalWrite(trig_pin, LOW);
}

void HR_SR04::echo_once() {
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);
}

long HR_SR04::read_once() {
    echo_once(); // send echo
    long duration = pulseIn(echo_pin, HIGH); // wait on high pulse back [blocking]
    return duration;
} 

// multiply the time it took for high pulse and divide by 2 accounting for the time to go to target and back
int HR_SR04::distance_cm() {
    long duration = read_once();
    return ((duration * 0.034) / 2);
}

int HR_SR04::distance_cm_average(int average_of) {
    int average = 0;
    for (unsigned int i = 0; i<average_of; i++) 
        average += distance_cm();
    return average/average_of;
}