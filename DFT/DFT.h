#ifndef DFT_H
#define DFT_H

#include <Math.h>



// computation of the frequency domain signals
extern void computeDFT(unsigned int *x, float* Re, float *Im, unsigned int N);

// scaling amplitudes (for a 10-bit DAC)
extern void scaleAmplitudes(float* Re, float* Im, unsigned int *Ampl, unsigned int N);

#endif