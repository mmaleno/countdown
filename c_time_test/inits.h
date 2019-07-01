// inits.h
// Created by Max Maleno, mmaleno@hmc.edu
// Last Modified 06/26/19
// Header file with init functions for c_time.c
// Adopted from my lab6_inits.h from E155 FA18
// Almost exclusively relevant to an RPi Model 3 B+

#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "defs.h"

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
