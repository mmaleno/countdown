/*
*   Filename:   inits.h
*   Creator:    Max Maleno
*   Contact:    mmaleno@hmc.edu
*   Updated:    07/07/19
*   
*   Notes:
*   - Header file with init functions for RPi
*   - Adopted from Max's lab6_inits.h written for HMC's E155 FA18
*   - Warning: IO files written for a RPi Model 3B (BCM 2837).
*     IO functionality not guaranteed for other RPi generations or CPUs.
*/

#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "defs.h"

/********************* Start from E155 *********************/

// Initiate GPIO reg map and assign base address to gpio
// From lab5_starter.c
void pioInit() {
	int  mem_fd;
	void *reg_map;

	// /dev/mem is a psuedo-driver for accessing memory in the Linux filesystem
	if ((mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) {
	      printf("can't open /dev/mem \n");
	      exit(-1);
	}

	reg_map = mmap(
	  NULL,             //Address at which to start local mapping (null means don't-care)
      BLOCK_SIZE,       //Size of mapped memory block
      PROT_READ|PROT_WRITE,// Enable both reading and writing to the mapped memory
      MAP_SHARED,       // This program does not have exclusive access to this memory
      mem_fd,           // Map to /dev/mem
      GPIO_BASE);       // Offset to GPIO peripheral

	if (reg_map == MAP_FAILED) {
      printf("gpio mmap error %d\n", (int)reg_map);
      close(mem_fd);
      exit(-1);
    }

	gpio = (volatile unsigned *)reg_map;
}

// Initiate Sytem Timer reg map and assign base address to sysTimer
// Based on pioInit()
void sysTimerInit() {
	int  mem_fd;
	void *reg_map_timer;

	// /dev/mem is a psuedo-driver for accessing memory in the Linux filesystem
	if ((mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) {
	      printf("can't open /dev/mem \n");
	      exit(-1);
	}

	reg_map_timer = mmap(
	  NULL,             //Address at which to start local mapping (null means don't-care)
      BLOCK_SIZE,       //Size of mapped memory block
      PROT_READ|PROT_WRITE,// Enable both reading and writing to the mapped memory
      MAP_SHARED,       // This program does not have exclusive access to this memory
      mem_fd,           // Map to /dev/mem
      SYSTEM_TIMER_BASE);       // Offset to GPIO peripheral

	if (reg_map_timer == MAP_FAILED) {
      printf("sysTimer mmap error %d\n", (int)reg_map_timer);
      close(mem_fd);
      exit(-1);
    }

	sysTimer = (volatile unsigned *)reg_map_timer;
}

/********************* End from E155 *********************/

/********************* Start from countdown *********************/

// If we are using an RPi, run RPi init functions
void machineInit() {
    
	// Run RPi-specific inits if we are running on a RPi
    if (OS_NAME == "linux")
    {
        pioInit();
        sysTimerInit();
    }
}

/********************* End from countdown *********************/
