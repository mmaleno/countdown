// myEasyIO.h
// Created by Max Maleno, mmaleno@hmc.edu
// Last Modified 06/26/19
// Header file with IO functions for c_time.c
// Adopted from my myEasyIO.h from E155 FA18
// Almost exclusively relevant to an RPi Model 3 B+

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
