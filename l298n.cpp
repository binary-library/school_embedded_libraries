#include "l298n.h"

L298N::L298N(int in0, int in1, int in2, int in3, int ena, int enb):
    ZK_5AD(in0, in1, in2, in3),
    ena(ena),
    enb(enb)
{}

void L298N::set_pwm(which_motor motor, int pwm) {
    // user input check
    if (pwm > 256 && pwm < 0)
        return;
    else if (motor == motor_one)
        analogWrite(ena, pwm);
    else if (motor == motor_two)
        analogWrite(enb, pwm);
}

void L298N::set_speed_percentage(which_motor motor,  int percnt) {
    if (percnt < 101 && percnt > -1) {
        int new_pwm = percnt * 2.55;
        set_pwm(motor, new_pwm);
    }
}
