#include "Globals.h"


// state of pulse length
unsigned int PLState;

// flag to send output
unsigned int flagDoOutput;


// sample index
int TDindex;

// state sequence d
double d[2];

// output coefficients
double a[2];

// input coefficients
double b[3];

// filter order (M=N)
unsigned int N;

// initialization  of global variables
void initVars(unsigned int ftype) {
  int i;
  flagDoOutput = FALSE;

  switch(ftype) {
	 case f_ButterLowPassOrd2: // create an order-2 Butterworth Lowpass
	 					       computeButter2LowPass(30700, 29069);
						       break;
	 case f_ButterHighPassOrd2: // create an order2 Butterworth Highpass
	                           computeButter2HighPass(36000, 29069);
						       break;
  }
  // pulse length state
  PLState = 0;
  // input signal index
  TDindex = WAVE_LEN-1;

  // zeroing state sequence d[]
  for (i=0; i<N; i++) 
     d[i] = 0;
  
}

// create a butterword second order low pass filter
void computeButter2LowPass(double fc, double fs) {
 
  double wp, sqrt2;
  N = 2;
  // calculating pre-warped cuttoff frequency
  wp = tan(PI*fc/fs);
  // square root of 2
  sqrt2 = sqrt(2);
  // calculating coefficients of digital filter
  // input coefficients
  b[0] = wp*wp/(1 + sqrt2*wp + wp*wp);
  b[1] = 2*wp*wp/(1 + sqrt2*wp + wp*wp);
  b[2] = wp*wp/(1 + sqrt2*wp + wp*wp);
  // output coefficients (a1 stored in a[0])
  a[0] = -2*(wp*wp-1)/(wp*wp + sqrt2*wp + 1);
  a[1] = -(wp*wp - sqrt2*wp + 1)/(wp*wp + sqrt2*wp + 1);
}
 

// create a butterword second order high pass filter
void computeButter2HighPass(double fc, double fs) {
   
  double wp, sqrt2;
  N = 2;
  // calculating pre-warped cuttoff frequency
  wp = tan(PI*fc/fs);
  // square root of 2
  sqrt2 = sqrt(2);
  // calculating coefficients of digital filter
  // input coefficients
  b[0] = (1 + sqrt2*wp)/(1 + sqrt2*wp + wp*wp);
  b[1] = -2/(1 + sqrt2*wp + wp*wp);
  b[2] = (1 - sqrt2*wp)/(1 + sqrt2*wp + wp*wp);
  // output coefficients (a0 stored in a[1])
  a[0] = -2*(wp*wp-1)/(wp*wp + sqrt2*wp + 1); // a1
  a[1] = -(wp*wp - sqrt2*wp + 1)/(wp*wp + sqrt2*wp + 1); //a2
}

// calculate Output
void calculateOutput(double input) {
 double dn, yn;
 unsigned int wrd;
 int k;
 dn = 0;
 yn =0; 
 for (k=N; k>0; k--) {
   // adding terms to dn (a[k-1] is ak)
   dn += a[k-1]*d[k-1];
   // additing terms to yn
   yn += b[k]*d[k-1];
   // shifting d[k-2] to the right
   if (k>=2)
   	 d[k-1] = d[k-2];
   
 }
 //adding last terms
 dn += input;
 yn += b[0]*dn;
 // inserting newest value of d in rolling buffer
 d[0] = dn;

 // now transmitting to DAC
 wrd = (unsigned int)(1023.0*yn);
 wrd = wrd << 2;
 sendWordSPI(wrd);
} 
