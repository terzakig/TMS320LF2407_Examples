#ifndef GLOBALS_H
#define GLOBALS_H

#include <math.h>

#define TRUE 1
#define FALSE 0

#define PI 3.14159265

#define N 256

#define mDFT 0
#define mFFT 1

// time domain signal x[]
extern double x[];

// frequecy domain signals
extern double ReX[]; // real part
extern double ImX[]; // imaginary part

// magnitudes
extern double Magnitudes[];


// ADC index for the Time Domain signal
extern unsigned int TDindex; 

// DFT enable flag
extern int EnableDFT;
// variable initialization
void initVars(void);
// Computes ReX, ImX with the simple DFT 
void computeDFT(void);
// transmit N magnitudes to the DAC
void dumpSignal(void);
// transmit ReX as a Time domain synthesized signal
void dumpTDSignal(void);

// *************** FFT Routines **********************


// Time domain signal transposition - Version #1
void transposeTDSignal1(void);
// Frequency domain composition in stages - Version #1
void computeFFT1(void);
void computeFFT2(void);
void computeInverseFFT1(void);
void computeInverseFFT2(void);

#endif