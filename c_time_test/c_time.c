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

    printf("TEST!! Unix Difference: %lu ---- ", diffUnixTime);

    static int times[5];
    times[0] = days;
    times[1] = hours;
    times[2] = minutes;
    times[3] = seconds;
    times[4] = (int)diffUnixTime;

    return times;
}



int main()
{
    int * times;
    while(1)
    {
        times = getRemainingTime();
        printf("Unix Difference: %d, ", times[4]);
        printf("Days: %d, ", times[0]);
        printf("Hours: %d, ", times[1]);
        printf("Minutes: %d, ", times[2]);
        printf("Seconds: %d\n", times[3]);
    }
    return 0;
}
