
#ifndef ZK_5AD_H
#define ZK_5AD_H
#include <Arduino.h>



/// \brief
/// an enum for which motor you want to pass to the function to spin them
/// \details
/// this enum will either be motor one or two, I could have used a boolean but for readibility this made the most sense
enum which_motor {motor_one, motor_two};

/// @file
/// \brief
/// An ADT for the motor driver ZK-5AD
/// \details
/// This is an ADT that gives functionality to the ZK-5AD motor driver
/// It can be used for easy control over the driver with readable code and a simple implimentation
/// The appropriate constructors and operators are provided.
class ZK_5AD {
private:
    int in0, in1, in2, in3;
public:
    /// \brief
    /// default constructor
    /// \details
    /// This constructor initializes all the pins of the target device.
    ZK_5AD(int in0, int in1, int in2, int in3);
    
    /// \brief
    /// setup the target device before use
    /// \details
    /// This function sets all the pins initialized in the constructor to out so they can be used by the rest of the instance.
    void setup();

    /// \brief
    /// turns the motor clockwise if the pins of the dc motor is setup correctly.  
    /// \details
    /// you are able to pass the enum of what motor you want to run.
    /// pins 'in0' and 'in1' will be used for "motor_one". 
    /// pins 'in2' and 'in3' will be used for "motor_two".
    /// if you setup the motors reversed you can easily either change the pins or pass the pins differently based on your setup
    void turn_clockwise(which_motor motor);

    /// \brief
    /// turns the motor counter-clockwise if the pins of the dc motor is setup correctly.
    /// \details
    /// This function does the exact same as the function 'turn_clockwise(which_motor motor)'.
    /// for more details look at the documentation of the said function.
    void turn_counter_clockwise(which_motor motor);

    /// \brief
    /// stops the motor abruptly of the motor passed through the arg.
    /// \details
    /// sets the pins of motor passed to LOW meaning it will stop and wont turn to whatever direction set before hand. 
    /// if used while motors werent spinning nothing will happen.
    void stop_motor(which_motor motor);
};

#endif ZK_5AD_HPP