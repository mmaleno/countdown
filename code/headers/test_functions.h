/*
*   Filename:   test_functions.c
*   Creator:    Max Maleno
*   Contact:    mmaleno@hmc.edu
*   Updated:    07/08/19
*   
*   Notes:
*   - Header file with test functions for development.
*   - Warning: IO files written for a RPi Model 3B (BCM 2837).
*     IO functionality not guaranteed for other RPi generations or CPUs.
*/

#include "simple_io.h"

//simple hello world led function
void blink(int pinNumber) {
    pinMode(pinNumber, OUTPUT);
    int i = 0;
    while(i < 3) {
        digitalWrite(pinNumber, LOW);
        delayMillis(250);
        digitalWrite(pinNumber, HIGH);
        delayMillis(250);
        i++;
    }
}

// main test function to run in countdown_main.c's main()
void test_main() {
    int rPin = 4;   // red
    int yPin = 17;  // green
    int gPin = 27;  // yellow
    int bPin = 22;  // blue

    blink(rPin);
    blink(yPin);
    blink(gPin);
    blink(bPin);
}
