#ifndef HR_SR04_H
#define HR_SR04_H

#include <Arduino.h>

/// @file
/// \brief
/// An ADT for the distance sensor HR_SR04
/// \details
/// This is an ADT that gives functionality to the HR_SR04 distance sensor
/// It can be used for easy readings with readable code and a simple implimentation
/// The appropriate constructors and operators are provided.
class HR_SR04 {
  int trig_pin, echo_pin;
public:

  /// \brief
  /// default constructor
  /// \details
  /// This constructor initializes all the pins of the target device.
  HR_SR04(int t_pin, int e_pin);

  /// \brief
  /// function that returns the duration of time elapsed till pulse
  /// \details
  /// this function calls the 'echo_once()' function and returns the duration it took till it received a pulse back.
  /// this function is used by 'distance_cm()' to actually make an estimate in cm but is still exposed for if you want to impliment it otherwise.
  long read_once();

  /// \brief
  /// function echo's a pulse.
  /// \details
  /// this function doesnt return anything, it simply send the device appropriate signals so it will send a ultrasonic pulse.
  void echo_once();

  /// \brief
  /// this function returns the estimated distance between the sensor and the object in front of it.
  /// \details
  ///  this function returns the estimated distance between the sensor and the object in front of it.
  int distance_cm();

  /// \brief
  /// this function returns an average of the distance between the sensor and the object in front of it based on the param passed.
  /// \details
  /// this function will return 'distance_cm()' function for 'average_of' amount of times and return the average of it, making for a better estimate.
  int distance_cm_average(int average_of);
};

#endif HR_SR04_H