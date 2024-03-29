/*
* File: c_time_old.c
*
* Author: Max Maleno
*
* Last Updated: 6/26/19
*
* Description: formerly main dev file, before RPi-specific files were added.
*
*/

#include <stdio.h>          // for our treasured print functions
#include <stdlib.h>
#include <time.h>           // to get the current system UNIX time

// graciously adapted from
// https://stackoverflow.com/questions/142508/how-do-i-check-os-with-a-preprocessor-directive
#if defined(__linux__)
    #define OS_NAME "linux"
#elif defined(__APPLE__)
    #define OS_NAME "mac"
#endif

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

// Outputs an int array of each individual digit from all time divisions.
// Takes int array times of the value of each time division.
// Output format: { day100s, day10s, day1s, hour10s, hour1s, minute10s, minute1s, second10s, second1s}
int * getDigits(int * times)
{
    // There are 9 elements according to the above output format
    static int digits[9];

    // Can calculate this outside of the for loop because it is unique to days
    digits[0] = times[0] / 100;

    /* The below for loop may make more sense if you see this pattern:

        timesIndex     digitIndex	    digitIndex's relation to i
            0	    	    0   	    	i
            0		        1	        	i+1
            0		        2	        	i+2
            1		        3	        	i+2
            1		        4	        	i+3
            2		        5	        	i+3
            2		        6	        	i+4
            3		        7	        	i+4
            3		        8	        	i+5
    
    */

    int i; // added outside for loop for compatibility with older compilers 

    for(i = 0; i<=3; i++)
    {
        digits[2*i+1] = times[i] / 10;  // extract 10s place
        digits[2*i+2] = times[i] % 10;  // extract 1s place
    }

    return digits;
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

// Outputs an int array of 1s (HIGHs) and 0s (LOWs) for each segment for the inputted int digit
int * digitToSegments(int digit)
{
    // a-g correspond to a segment              a    b    c    d    e    f    g
    // numbers taken from e155 lab2             |    |    |    |    |    |    |
    static int zeroSegments[7]          =   {   0,   0,   0,   0,   0,   0,   1   };
    static int oneSegments[7]           =   {   1,   0,   0,   1,   1,   1,   1   };
    static int twoSegments[7]           =   {   0,   0,   1,   0,   0,   1,   0   };
    static int threeSegments[7]         =   {   0,   0,   0,   0,   1,   1,   0   };
    static int fourSegments[7]          =   {   1,   0,   0,   1,   1,   0,   0   };
    static int fiveSegments[7]          =   {   0,   1,   0,   0,   1,   0,   0   };
    static int sixSegments[7]           =   {   0,   1,   0,   0,   0,   0,   0   };
    static int sevenSegments[7]         =   {   0,   0,   0,   1,   1,   1,   1   };
    static int eightSegments[7]         =   {   0,   0,   0,   0,   0,   0,   0   };
    static int nineSegments[7]          =   {   0,   0,   0,   1,   1,   0,   0   };

    // below in progress
    int numCharacters = 9;
    char topLine[2*(3*numCharacters)-1];
    
    // Output the corresponding array based on the input int
    if (digit == 0) return zeroSegments;
    if (digit == 1) return oneSegments;
    if (digit == 2) return twoSegments;
    if (digit == 3) return threeSegments;
    if (digit == 4) return fourSegments;
    if (digit == 5) return fiveSegments;
    if (digit == 6) return sixSegments;
    if (digit == 7) return sevenSegments;
    if (digit == 8) return eightSegments;
    if (digit == 9) return nineSegments;

    // In case something goes wrong (inputted int is not 0-9)
    static int defaultValues[7] = { 0, 0, 0, 0, 0, 0, 0 };

    return defaultValues;
}

// Main function to run.  Currently has changing purpose based on stage of development
int main()
{
    // Wet Season's (Sept 07 2019 18:01 or 06:01pm) UNIX time
    unsigned long eventUnixTime = 1567904460;

    int * times;
    int * digits;
    int * selectedDigit;
    
    // Infinite loop until CRTL+C
    while(1)
    {
        times = getRemainingTime(eventUnixTime);
        digits = getDigits(times);
        delay();                        // for readablity
        ///*
        printf("Unix Difference: %d, ", times[4]);
        printf("Days: %d (hundreds %d - tens %d - ones %d) ; ", times[0], digits[0], digits[1], digits[2]);
        printf("Hours: %d, (tens %d - ones %d) ; ", times[1], digits[3], digits[4]);
        printf("Minutes: %d, (tens %d - ones %d) ; ", times[2], digits[5], digits[6]);
        printf("Seconds: %d (tens %d - ones %d) ; \n", times[3], digits[7], digits[8]);
        //*/
        //printf("%s\n", OS_NAME);
        //selectedDigit = digitToSegments(10);
        //printf("%d %d %d %d\n", selectedDigit[0], selectedDigit[3], selectedDigit[4], selectedDigit[5]);
    }
    return 0;
}
