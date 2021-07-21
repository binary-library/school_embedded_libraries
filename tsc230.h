#ifndef TSC230_H
#define TSC230_H
#include "src/rgb.hpp"
#include <Arduino.h>

/// \brief
/// a simple struct to keep track of the current frequency of the color sensor.
/// \details
/// An simple enum providing for 4 options, these are the options provided by the color sensor.
/// the frequency is how fast the sensor outputs data, 20% is around 120kHz.
/// for faster readings can be set to 'hundred' and for slower processors to 'two'.
/// 'zero' will turn the sensor off and it will no longer output data.
enum frequencies {zero, two, twenty, hundred};

/// \brief
/// a simple struct to keep track of the current calibration of the color sensor.
/// declared outside of the class so that the user can make an instance himself and give manual calibration values for his sensor.
/// \details
/// An struct with 2 RGB classes inside. The RGB class and methods are defined inside of the src folder in the lib.
/// The color sensor needs to be aware of the lowest and highest values (Base and Ceiling) it reads so that we can properly map it to actual RGB values.
/// It can be used for easy readings with readable code and a simple implimentation
struct TSC_230_calibration {
    RGB base, ceil;
};

/// @file
/// \brief
/// An ADT for the color sensor TSC_230
/// \details
/// This is an ADT that gives functionality to the TSC_230 color sensor
/// It can be used for easy readings with readable code and a simple implimentation
/// The appropriate constructors and operators are provided.
class TSC_230 {
private:
    TSC_230_calibration cur_cal;
    bool manual_calibration; // if set false it will calibrate itself 
    frequencies freq;
    int s0, s1, s2, s3, out, base, ceil;
public:
    /// \brief
    /// default constructor
    /// \details
    /// This constructor initializes all the pins of the target device.
    TSC_230(int s0, int s1, int s2, int s3, int out);

    /// \brief
    /// setup the target device before use
    /// \details
    /// This function sets all the pins initialized in the constructor to out so they can be used by the rest of the instance.
    void setup();

    /// \brief
    /// function to set the frequency of the sensor
    /// \details
    /// the frequency is how fast the sensor outputs data, 20% is around 120kHz.
    /// for faster readings can be set to 'hundred' and for slower processors to 'two'.
    /// 'zero' will turn the sensor off and it will no longer output data.
    void set_freq_scale(frequencies in);

    /// \brief
    /// a function to manually input a calibration model for the color sensor, it also stops auto_calibrating
    /// \details
    /// You must give your own calibration model and it will read values based on that model.
    /// it will stop the instance calibrating itself, it can be turned back on again by using the function 'set_calibration_auto()'.
    /// note that it will have to calibrate back from the start again.
    void set_calibration_manual(TSC_230_calibration c);

    /// \brief
    /// a function to set the instance to calibrate itself
    /// \details
    /// This function is called at the setup and doesnt need to be called if you didnt set it manually.
    /// the process works by reading data and seeing if the data PW values are lower or higher than the known lows and highs.
    /// it will than adjust the current calibration on the spot. the calibration is only usefull for converting the PW values to a good RGB estimate.
    void set_calibration_auto();

    /// \brief
    /// a function to calibrate for a certain amount of time, this function doesnt return data and is purely meant for calibrating the current_calibration model
    /// \details
    /// Call this function if you want to calibrate for a certain amount of time.
    /// The model can only calibrate by reading data for example 'read_rgb()'. this function calls read_rgb a bunch of times in the given amount of time.
    /// it will than adjust the current calibration on the spot. the calibration is only usefull for converting the PW values to a good RGB estimate.
    /// so if you arent planning on using my conversion method you can skip this and just read in any color you want.
    void calibrate_in_seconds(int seconds);

    /// \brief
    /// a function to read the raw PW val for any given color
    /// \details
    /// Takes in a color enum, can be the following: red, green, blue.
    /// the enum is locating in the RGB header file in the src folder.
    /// note: these are the raw values without any conversion to RGB
    int read_color(color in);

    /// \brief
    /// a function to convert the raw PW values to rgb.
    /// \details
    /// this function is used by read_rgb to convert the raw PW values to rgb using the current calibration model.
    /// it works by using the lows and highs of the sensor for every color and mapping it to a range of 0 - 255.
    /// can be done without map function like so -> ((x-lowest_sensor_val) * 255) / ((highest_sensor_val - lowest_sensor_val) + 255)
    int pw_to_rgb(color in, int pw);

    /// \brief
    /// a function to read RGB from the sensor
    /// \details
    /// this function uses function defined earlier in this doc to give a rough RGB estimate
    RGB read_rgb();
};

#endif TSC230_H