// digits.h
// Created by Max Maleno, mmaleno@hmc.edu
// Last Modified 06/26/19
// Header file with digit-related functions for c_time.c

// Outputs an int array of each individual digit from all time divisions.
// Takes int array times of the value of each time division.
// Output format: { day100s, day10s, day1s, hour10s, hour1s, minute10s, minute1s, second10s, second1s}
int * getDigits(int * times)
{
    // There are 9 elements according to the above output format
    static int digits[9];

    // Can calculate this outside of the for loop because it is unique to days
    digits[0] = times[0] / 100;

    /* The below for loop may make more sense if you see this pattern:

        timesIndex     digitIndex	    digitIndex's relation to i
            0	    	    0   	    	i
            0		        1	        	i+1
            0		        2	        	i+2
            1		        3	        	i+2
            1		        4	        	i+3
            2		        5	        	i+3
            2		        6	        	i+4
            3		        7	        	i+4
            3		        8	        	i+5
    
    */

    int i; // added outside for loop for compatibility with older compilers 

    for(i = 0; i<=3; i++)
    {
        digits[2*i+1] = times[i] / 10;  // extract 10s place
        digits[2*i+2] = times[i] % 10;  // extract 1s place
    }

    return digits;
}

// Outputs an int array of 1s (HIGHs) and 0s (LOWs) for each segment for the inputted int digit
int * digitToSegments(int digit)
{
    // a-g correspond to a segment              a    b    c    d    e    f    g
    // numbers taken from e155 lab2             |    |    |    |    |    |    |
    static int zeroSegments[7]          =   {   0,   0,   0,   0,   0,   0,   1   };
    static int oneSegments[7]           =   {   1,   0,   0,   1,   1,   1,   1   };
    static int twoSegments[7]           =   {   0,   0,   1,   0,   0,   1,   0   };
    static int threeSegments[7]         =   {   0,   0,   0,   0,   1,   1,   0   };
    static int fourSegments[7]          =   {   1,   0,   0,   1,   1,   0,   0   };
    static int fiveSegments[7]          =   {   0,   1,   0,   0,   1,   0,   0   };
    static int sixSegments[7]           =   {   0,   1,   0,   0,   0,   0,   0   };
    static int sevenSegments[7]         =   {   0,   0,   0,   1,   1,   1,   1   };
    static int eightSegments[7]         =   {   0,   0,   0,   0,   0,   0,   0   };
    static int nineSegments[7]          =   {   0,   0,   0,   1,   1,   0,   0   };

    // below in progress
    int numCharacters = 9;
    char topLine[2*(3*numCharacters)-1];
    
    // Output the corresponding array based on the input int
    if (digit == 0) return zeroSegments;
    if (digit == 1) return oneSegments;
    if (digit == 2) return twoSegments;
    if (digit == 3) return threeSegments;
    if (digit == 4) return fourSegments;
    if (digit == 5) return fiveSegments;
    if (digit == 6) return sixSegments;
    if (digit == 7) return sevenSegments;
    if (digit == 8) return eightSegments;
    if (digit == 9) return nineSegments;

    // In case something goes wrong (inputted int is not 0-9)
    static int defaultValues[7] = { 0, 0, 0, 0, 0, 0, 0 };

    return defaultValues;
}
