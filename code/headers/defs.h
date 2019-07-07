/*
*   Filename:   defs.h
*   Creator:    Max Maleno
*   Contact:    mmaleno@hmc.edu
*   Updated:    07/07/19
*   
*   Notes:
*   - Header file with definitions for countdown_main.c
*   - Adopted from Max's defs.h written for HMC's E155 FA18
*   - Warning: IO files written for a RPi Model 3B (BCM 2837).
*     IO functionality not guaranteed for other RPi generations or CPUs.
*/

/********************* Start from countdown *********************/

// graciously adapted from
// https://stackoverflow.com/questions/142508/how-do-i-check-os-with-a-preprocessor-directive
#if defined(__linux__)
    #define OS_NAME "linux"
#elif defined(__APPLE__)
    #define OS_NAME "mac"
#endif

/********************* End from countdown *********************/


/********************* Start from E155 *********************/

// GPIO FSEL Types
#define INPUT  0
#define OUTPUT 1
#define ALT0   4
#define ALT1   5
#define ALT2   6
#define ALT3   7
#define ALT4   3
#define ALT5   2

// Putting offsets of addresses into easy names
#define GPFSEL   ((volatile unsigned int *) (gpio + 0))
#define GPSET    ((volatile unsigned int *) (gpio + 7))
#define GPCLR    ((volatile unsigned int *) (gpio + 10))
#define GPLEV    ((volatile unsigned int *) (gpio + 13))

// The standard for our chip
#define INPUT  0
#define OUTPUT 1

// Addresses
#define BCM2836_PERI_BASE        0x3F000000
#define GPIO_BASE               (BCM2836_PERI_BASE + 0x200000)
#define BLOCK_SIZE (4*1024)

// Readable output level definitions, self-written
#define LOW 	0
#define HIGH 	1

// Pointer that will be memory mapped when pioInit() is called
volatile unsigned int *gpio; //pointer to base of gpio

// Timer addresses offsets
#define SYSTEM_TIMER_CS	   ((volatile unsigned int *) (sysTimer + 0))
#define SYSTEM_TIMER_CLO   ((volatile unsigned int *) (sysTimer + 1))
#define SYSTEM_TIMER_CHI   ((volatile unsigned int *) (sysTimer + 2))
#define SYSTEM_TIMER_C0    ((volatile unsigned int *) (sysTimer + 3))
#define SYSTEM_TIMER_C1    ((volatile unsigned int *) (sysTimer + 4))
#define SYSTEM_TIMER_C2    ((volatile unsigned int *) (sysTimer + 5))
#define SYSTEM_TIMER_C3    ((volatile unsigned int *) (sysTimer + 6))

#define SYSTEM_TIMER_BASE	(BCM2836_PERI_BASE + 0x3000)

// pointer to base of systimer
volatile unsigned int *sysTimer;

/********************* End from E155 *********************/
