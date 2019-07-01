// c_time.c
// Created by Max Maleno, mmaleno@hmc.edu
// Last Modified 06/26/19
// Main development file for wet season countdown timer.

#include "defs.h"
#include "delays.h"
#include "inits.h"
#include "myEasyIO.h"

#include "time_calc.h"
#include "digits.h"

// Main function to run.  Currently has changing purpose based on stage of development
int main()
{
    if (OS_NAME == "linux")
    {
        pioInit();
        sysTimerInit();
    }
    
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
