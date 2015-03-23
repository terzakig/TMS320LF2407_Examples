#ifndef GLOBALS_H
#define GLOBALS_H

#include "Peripherals.h"
#include <math.h>


#define TRUE 1
#define FALSE 0

#define PI 3.14159265

//kernel length is M+1 
#define M 60
// number of points of the virtyual input (sum of sinusoids)
#define WAVE_LEN 120

// filter identification constants
#define f_MovingAverage   0
#define f_WSinc_LowPass   1
#define f_WSinc_HighPass  2
#define f_WSinc_BandPass  3

// pulse length state
extern unsigned int PLState;

// scaled time domain signal
extern double x[];

// convolution kernel
extern double kernel[];

// sample index
extern int TDindex;

// flag to enable output computations and transmission
extern unsigned int flagDoOutput;


// global variables initialization
void initVars(unsigned int ftype);

// convolution step (calculation of y[n]) 
void shiftConvolve(double input);

// create an m+1 point input moving average kernel
void createMovingAverageKernel(double* h,unsigned int m);

// create an m+1 point low-pas sinc windowed kernel
void createLowPassSincKernel(double *h, double fc, unsigned int m);
 
// create an m+1 point high-pass windowed kernel
void createHighPassSincKernel(double *h, double fc, unsigned int m);

// create an m+1 point band-pass windowed-sinc kernel
void createBandPassSincKernel(double *h, double *hl, double* hh, unsigned int m);

#endif