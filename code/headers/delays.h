/*
*   Filename:   delays.h
*   Creator:    Max Maleno
*   Contact:    mmaleno@hmc.edu
*   Updated:    07/07/19
*   
*   Notes:
*   - Header file with delay functions for countdown_main.c
*   - Adopted from Max's lab6_delays.h written for HMC's E155 FA18
*   - Warning: IO files written for a RPi Model 3B (BCM 2837).
*     IO functionality not guaranteed for other RPi generations or CPUs.
*/

#include "defs.h"

// Delay in microseconds, the lowest-level delay function.
// Based on function delayMicros from
// Digital Deisgn and Computer Architecture (Harris & Harris)
void delayMicros(int micros) {
	
	// Set the compare register
	*SYSTEM_TIMER_C1 = *SYSTEM_TIMER_CLO + micros;
	
	// Reset match flag to 0
	*SYSTEM_TIMER_CS |= 0b10;

	// Wait until match flag is set
	while ((*SYSTEM_TIMER_CS >> 1) == 0);
}

// Delay in milliseconds, a more human-usable form of delayMicros
// Based on function delayMillis from
// Digital Deisgn and Computer Architecture (Harris & Harris)
void delayMillis(int millis) {
	delayMicros(millis*1000); // 1000 μs per ms
}
