/*
*   Filename:   simple_IO.h
*   Creator:    Max Maleno
*   Contact:    mmaleno@hmc.edu
*   Updated:    07/07/19
*   
*   Notes:
*   - Header file with IO functions for countdown_main.c
*   - Adopted from Max's myEasyIO.h written for HMC's E155 FA18
*   - Warning: IO files written for a RPi Model 3B (BCM 2837).
*     IO functionality not guaranteed for other RPi generations or CPUs.
*/

#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "defs.h"

// Set pin mode, from class
void pinMode(int pin, int mode) {
	int reg = pin/10;
	int offset = (pin%10)*3;
	GPFSEL[reg] &= ~((0b111 & ~mode) << offset);
	GPFSEL[reg] |=   (0b111 &  mode) << offset;
}

// Read either high (1) or low (0) from pin, from class
int digitalRead(int pin) {
	int reg = pin/32;
	int offset = pin%32;
	return (GPLEV[reg] >> offset) & 0x1;
}

// Write either high (1) or low (0) from pin, from class
void digitalWrite(int pin, int val) {
	int reg = pin/32;
	int offset = pin%32;
	if (val) {
		GPSET[reg] = 1 << offset;
	}
	else {
		GPCLR[reg] = 1 << offset;
	}
}
