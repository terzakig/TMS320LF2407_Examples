#ifndef GLOBALS_H
#define GLOBALS_H

#include "Peripherals.h"
#include <math.h>


#define TRUE 1
#define FALSE 0

#define PI 3.14159265


// number of points of the virtual input (sum of sinusoids)
#define WAVE_LEN 120

#define f_ButterLowPassOrd2  0
#define f_ButterHighPassOrd2  1
 

// state of pulse length
extern unsigned int PLState;

// flag to send output
extern unsigned int flagDoOutput;

// sample index
extern int TDindex;

// state sequnce d
extern double d[];

// output coefficients
extern double a[];

// input coefficients
extern double b[];

// filter order (M=N)
extern unsigned int N;

// initialization  of global variables
void initVars(unsigned int ftype);

// create a butterword second order low pass filter
void computeButter2LowPass(double fc, double fs);
 

// create a butterword second order high pass filter
void computeButter2HighPass(double fc, double fs);

// calculate filter output and transmit to DAC
void calculateOutput(double input);


#endif