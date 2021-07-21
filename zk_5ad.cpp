#include "zk_5ad.h"
#include "Arduino.h"

ZK_5AD::ZK_5AD(int in0, int in1, int in2, int in3):
    in0(in0),
    in1(in1),
    in2(in2),
    in3(in3)
{}
    
void ZK_5AD::setup() {
    pinMode(in0, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
}

void ZK_5AD::turn_clockwise(which_motor motor) {
    if (motor == motor_one) {
        digitalWrite(in0, HIGH);
        digitalWrite(in1, LOW); 
    } else if (motor == motor_two) {
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
    }
}

void ZK_5AD::turn_counter_clockwise(which_motor motor) {
    if (motor == motor_one) {
        digitalWrite(in0, LOW);
        digitalWrite(in1, HIGH); 
    } else if (motor == motor_two) {
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
    }
}

void ZK_5AD::stop_motor(which_motor motor) {
    if (motor == motor_one) {
        digitalWrite(in0, LOW);
        digitalWrite(in1, LOW); 
    } else if (motor == motor_two) {
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
    }
}
