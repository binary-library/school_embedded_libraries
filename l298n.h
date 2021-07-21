#ifndef L298N_H
#define L298N_H
#include <Arduino.h>
#include <zk_5ad.h>

/// @file
/// \brief
/// An ADT for the motor driver L298N
/// \details
/// This is an ADT that gives functionality to the L298N motor driver
/// It can be used for easy control over the driver with readable code and a simple implimentation.
/// It uses the AK_5AD class and inherits from it. Read the ZK_5AD docs first for more info
/// The appropriate constructors and operators are provided.
class L298N : public ZK_5AD {
private:
    int ena, enb;    
public:
    /// \brief
    /// default constructor
    /// \details
    /// This constructor initializes all the pins of the target device.
    L298N(int in0, int in1, int in2, int in3, int ena, int enb);

    /// \brief
    /// function to set the motor spinning at given PWM, pass what motor needs to be set to set speed.
    /// \details
    /// sets the PWM for given motor, PWM must be between 0 and 255. If the number is outside that range it wont do anything.
    void set_pwm(which_motor motor,  int pwm);

    /// \brief
    /// function to set the motor spinning at given percentage, pass what motor needs to be set to set speed.
    /// \details
    /// sets the PWM for given motor for given percentage, percentage must be between 0 and 100. If the number is outside that range it wont do anything.
    void set_speed_percentage(which_motor motor,  int percnt);
};

#endif L298N_H