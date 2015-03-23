#include "Globals.h"

// state of pulse length
unsigned int PLState;

// flag to send output
unsigned int flagDoOutput;

// scaled time domain signal
double x[M+1];

// sample index
int TDindex;

// convolution kernel
double kernel[M+1];



// initialization  of global variables
void initVars(unsigned int ftype) {
  int i;
  double hl[M/2+1], hh[M/2+1];
  flagDoOutput = FALSE;

  switch(ftype) {
	 case f_MovingAverage: // create a moving average filter kernel
	 					   createMovingAverageKernel(kernel, M);
						   break;
	 case f_WSinc_LowPass: // create a windowed low-pass kernel
	                       createLowPassSincKernel(kernel, 0.11, M);
						   break;
	 case f_WSinc_HighPass: // create a windows high-pass kernel
						   createHighPassSincKernel(kernel, 0.2, M);
	    					break;
	 case f_WSinc_BandPass: // create a windowed band-pass kernel
						    createLowPassSincKernel(hl, 0.37, M/2);
							createHighPassSincKernel(hh, 0.1, M/2);
							createBandPassSincKernel(kernel, hl, hh, M); 
						    break;
  }
  // pulse length state
  PLState = 0;
  // input signal index
  TDindex = WAVE_LEN-1;
  // zero input buffer
  for (i=0; i<=M; i++)
     x[i] = 0;
}

// convolution computations
void shiftConvolve(double input) {
  int i;
  unsigned int wrd; 
  double sum;
  sum = 0;
  // convolving and shifting input buffer
  for (i=M; i>0; i--) {
     // shifting
	 x[i] = x[i-1];
     // summing 
     sum += kernel[i] * x[i];
  }
  // inserting newest input in the first position
  x[0] = input;
  // last sum term
  sum += kernel[0]*x[0];
  
  // transmitting result to DAC
  wrd = (unsigned int)(sum * 1023.0);
  // shift two bits right
  wrd = wrd << 2;
  // transmit 
  sendWordSPI(wrd);
} 


// create a movig average kernel
void createMovingAverageKernel(double *h, unsigned int m) {
  int i;
  for (i=0; i<=m; i++) 
    h[i] = 1.0/(1.0*m+1);
} 


// create a low-pass sinc windowed kernel
void createLowPassSincKernel(double* h, double fc, unsigned int m) {
  int i;
  double BMWindow, HWindow, sum, K;
  sum = 0;
  for (i=0; i<=m; i++) {
    // Hamming window
    HWindow = 0.54 - 0.46*cos(2*PI/m);
    // Blackman window
    BMWindow = 0.42 - 0.5 * cos(2 * PI * i / m) + 0.08*cos(4 * PI * i / m);
    if (i == m/2) 
		h[i] = BMWindow * (2 * PI * fc); // avoid division by zero
	else  
    	h[i] = BMWindow * sin(2 * PI * fc * (i - m/2)) / (i - m/2);
  	// summing kernel points
  	sum += h[i];
  }	
  // computing normalization factor
  K = 1/ sum;
  // normalizing kernel points
  for (i=0; i<=m; i++)
	h[i] *= K;
} 

// create a high-pass windowed sinc  kernel
void createHighPassSincKernel(double* h, double fc, unsigned int m) {
  int i;
  double sum, HWindow, BWindow, K;
  // creating corresponding low-pass windowed kernel
  createLowPassSincKernel(h, fc, m);

  //Now performing spectral inversion
  for (i=0; i<=m; i++)
	if (i == m/2) // subtracting from 1
		h[i] = 1-h[i];
	else // subtracting from 0 (negating).
		h[i] = -h[i];

}


// create a band-pass windowed-sinc kernel 
void createBandPassSincKernel(double* h, double *hl, double *hh, unsigned int m) {
  int n, k;
  
  // calculating band pass kernel
  for (n=0; n<=m; n++) {
     h[n] = 0;
	 // convolving
	 if (n<=m/2)
     	for (k = 0; k<=n; k++)
			h[n] += hl[k]*hh[n-k];
	else 
		for (k=n-m/2; k<=m/2; k++)
			h[n] += hl[k]*hh[k-(n-m/2)];
  }

}