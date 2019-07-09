/*
*   Filename:   countdown_main.c
*   Creator:    Max Maleno
*   Contact:    mmaleno@hmc.edu
*   Updated:    07/07/19
*   
*   Notes:
*   - Main development file for wet season countdown timer.
*   - Warning: IO files written for a RPi Model 3B (BCM 2837).
*     IO functionality not guaranteed for other RPi generations or CPUs.
*/

/*  Lastest commit:
    - Cleaned up file decription comments
    - Added TODO field in countdown_main.c
    - Added commit field in countdown_main.c
    - Moved a ton of files around
    - Renamed unclear filenames
    - Restructured machine-specific inits and includes
*/

/*  TODO:
    - run this new version on pi
*/

#if defined(__linux__)
    #include "headers/delays.h"
    #include "headers/simple_io.h"
#endif

#include "headers/defs.h"
#include "headers/inits.h"

#include "headers/time_calc.h"
#include "headers/digits.h"

// Main function to run.  Currently has changing purpose based on stage of development
int main()
{
    // Run init functions based on which machine is running
    machineInit();
    
    // Wet Season's UNIX time (Sept 07 2019 US-Pacific 18:01 or 06:01pm)
    // Website to find UNIX time: https://www.epochconverter.com/
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
