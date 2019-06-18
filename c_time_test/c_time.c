#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * timer()
{
    unsigned long eventUnixTime = 1567904460;
    unsigned long nowUnixTime = (unsigned long)time(NULL);
    unsigned long diffUnixTime = eventUnixTime - nowUnixTime;

    static int days, hours, minutes, seconds;

    days = diffUnixTime / (60*60*24);
    hours = (diffUnixTime % (60*60*24)) / (60*60);
    minutes = ((diffUnixTime % (60*60*24)) % (60*60)) / 60;
    seconds = (((diffUnixTime % (60*60*24)) % (60*60)) % 60);

    
    printf("Unix Difference: %lu, ", diffUnixTime);
    printf("Days: %d, ", days);
    printf("Hours: %d, ", hours);
    printf("Minutes: %d, ", minutes);
    printf("Seconds: %d\n", seconds);

    static int times[4] = {days, hours, minutes, seconds};

    return times;
}



int main()
{
    while(1) timer();
    return 0;
}