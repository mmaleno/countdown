// delays.h
// Created by Max Maleno, mmaleno@hmc.edu
// Last Modified 06/26/19
// Header file with delay functions for c_time.c
// Adopted from my lab6_delays.h from E155 FA18
// Almost exclusively relevant to an RPi Model 3 B+

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
