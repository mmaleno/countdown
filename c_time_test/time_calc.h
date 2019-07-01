// time_calc.h
// Created by Max Maleno, mmaleno@hmc.edu
// Last Modified 06/26/19
// Header file with time-based functions for c_time.c

#include "time.h"           // to get the current system UNIX time

// Outputs an int array of time divisions until unsigned long eventUnixTime
// Website to find UNIX time: https://www.epochconverter.com/
// Output format: { days, hours, minutes, seconds, diffUnixTime }
int * getRemainingTime(unsigned long eventUnixTime)
{
    // Use time library to get the current system time, and then subtract that
    // from the event's time to see how many seconds remain until event
    unsigned long nowUnixTime = (unsigned long)time(NULL);
    unsigned long diffUnixTime = eventUnixTime - nowUnixTime;

    // create variables for time divisions
    int days, hours, minutes, seconds;

    // calculate time divisions from the amount of remaining seconds until event
    days = diffUnixTime / (60*60*24);
    hours = (diffUnixTime % (60*60*24)) / (60*60);
    minutes = ((diffUnixTime % (60*60*24)) % (60*60)) / 60;
    seconds = (((diffUnixTime % (60*60*24)) % (60*60)) % 60);

    // pack time division numbers into output array
    // times format: { days, hours, minutes, seconds, diffUnixTime}
    static int times[5];
    times[0] = days;
    times[1] = hours;
    times[2] = minutes;
    times[3] = seconds;
    times[4] = (int)diffUnixTime;

    return times;
}

// Useful delay function to make console prints easier to read.
// **Delays for different times depending on clock of machine.** //
void delay()
{

    int c; // added outside for loop for compatibility with older compilers
    int d; // added outside for loop for compatibility with older compilers
    if (OS_NAME == "linux") for (c = 1; c <= 5000; c++) for (d = 1; d <= 5000; d++) {}
    else for (c = 1; c <= 10000; c++) for (d = 1; d <= 10000; d++) {}
}
