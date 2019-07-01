#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Last edited 6/17/19

//  Use the below code to infinitely print the remaining time
void timer()
{
    unsigned long eventUnixTime = 1567904460;
    unsigned long nowUnixTime = (unsigned long)time(NULL);
    unsigned long diffUnixTime = eventUnixTime - nowUnixTime;

    int days, hours, minutes, seconds;

    days = diffUnixTime / (60*60*24);
    hours = (diffUnixTime % (60*60*24)) / (60*60);
    minutes = ((diffUnixTime % (60*60*24)) % (60*60)) / 60;
    seconds = (((diffUnixTime % (60*60*24)) % (60*60)) % 60);

    
    printf("Unix Difference: %lu, ", diffUnixTime);
    printf("Days: %d, ", days);
    printf("Hours: %d, ", hours);
    printf("Minutes: %d, ", minutes);
    printf("Seconds: %d\n", seconds);
}



int main()
{
    while(1) timer();
    return 0;
}