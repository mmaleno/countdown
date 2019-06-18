#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * getRemainingTime()
{
    unsigned long eventUnixTime = 1567904460;
    unsigned long nowUnixTime = (unsigned long)time(NULL);
    unsigned long diffUnixTime = eventUnixTime - nowUnixTime;

    int days, hours, minutes, seconds;

    days = diffUnixTime / (60*60*24);
    hours = (diffUnixTime % (60*60*24)) / (60*60);
    minutes = ((diffUnixTime % (60*60*24)) % (60*60)) / 60;
    seconds = (((diffUnixTime % (60*60*24)) % (60*60)) % 60);

    static int times[5];
    times[0] = days;
    times[1] = hours;
    times[2] = minutes;
    times[3] = seconds;
    times[4] = (int)diffUnixTime;

    return times;
}

int * getDigits(int * times)
{
    int dayHundreds, dayTens, dayOnes, hourTens, hourOnes,
        minutesTens, minutesOnes, secondsTens, secondsOnes;
    
    static int digits[9]; // 3 days, 2 hours, 2 minutes, 2 seconds

    digits[0] = times[0] / 100;

    for(int i = 0; i<6; i++)
    {
        digits[2*i+1] = times[i] / 10;
        digits[2*i+2] = times[i] % 10;
    }

    return digits;
}

void delay()
{
    int c, d;
    
    for (c = 1; c <= 10000; c++) for (d = 1; d <= 10000; d++) {}

}

// TODO: make function that takes an int and outputs array of segment on/offs

int main()
{
    int * times;
    int * digits;
    while(1)
    {
        times = getRemainingTime();
        digits = getDigits(times);
        delay();                        // for readablity
        /*
        printf("Unix Difference: %d, ", times[4]);
        printf("Days: %d (hundreds %d - tens %d - ones %d) ; ", times[0], digits[0], digits[1], digits[2]);
        printf("Hours: %d, (tens %d - ones %d) ; ", times[1], digits[3], digits[4]);
        printf("Minutes: %d, (tens %d - ones %d) ; ", times[2], digits[5], digits[6]);
        printf("Seconds: %d (tens %d - ones %d) ; \n", times[3], digits[7], digits[8]);
        */
    }
    return 0;
}
