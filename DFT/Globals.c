#include "Globals.h"

// time domain signal
double x[N];

// frequency domain signal
double ReX[N]; // real part
double ImX[N]; // imaginary part

// Magnitudes
double Magnitudes[N];

// ADC index for the Time Domain signal
unsigned int TDindex; 

// DFT enable flag
int EnableDFT;

// variable initialization (and allocation)
void initVars(void) {
  
  EnableDFT = FALSE;
  TDindex = 0;

} 

void computeDFT(void) {

	unsigned int n, k;
	double R, I;
	         
  	for (k = 0; k < N ; k++) {
       	R = I = 0;
       	for (n = 0; n < N; n++) {

          	R += x[n] * cos(2 * PI * n *k / (1.0*N));
          	I += -x[n] * sin(2 * PI * n *k / (1.0*N));		 
        
        }
		// normalizing sums by 1/N 
        R /= (1.0*N);
        I /= (1.0*N);
		// storing magnitude
		Magnitudes[k] = sqrt(R*R + I*I);
		// storing ReX and ImX
		ReX[k] = R;
		ImX[k] = I;
    }
}

// send N magnitudes to the DAC
void dumpSignal(void) {
unsigned int i, wrd;

  for (i=0; i<N; i++) {
	wrd = (int)(Magnitudes[i]*1023.0);
	wrd = wrd << 2;
	sendWordSPI(wrd);
  }
  // transmitting a zero
  wrd = 0;
  sendWordSPI(wrd);
}

// send N magnitudes to the DAC
void dumpTDSignal(void) {
unsigned int i,j, wrd;

  for (i=0; i<N; i++) {
	if (ReX[i]>0)
	   wrd = (int)(ReX[i]*1023.0);
	else 
	  wrd = -(int)(ReX[i]*1023.0);
	wrd = wrd << 2;
	sendWordSPI(wrd);
  }
  // transmitting a zero
  wrd = 0;
  sendWordSPI(wrd);
  // delay
  for (j=0; j<20000; j++);
}

void transposeTDSignal2(void) {
    int i, j, k;
    ReX[N - 1] = x[N - 1];

    j = 0;
    for (i = 0; i < N - 1; i++) {
       ReX[i] = x[j];
       ImX[i] = 0;
       k = N / 2;

       while (k <= j) {
         j -= k;
         k /= 2;
        }

       j += k;
    }

}

void transposeFDSignal2(void) {
    int i, j, k;
	double *tempR, *tempI;
    // allocating temporary arrays
    tempR = (double*)malloc(sizeof(double)*N);
    tempI = (double*)malloc(sizeof(double)*N);
    // copying frequency domain signals
	for (i=0; i<N; i++) {
	   tempR[i] = ReX[i];
	   tempI[i] = ImX[i];
	}
	tempR[N-1] = ReX[N-1];
	tempI[N-1] = ReX[N-1];
    j = 0;
    for (i = 0; i < N - 1; i++) {
       ReX[i] = tempR[j];
       ImX[i] = tempI[j];
       k = N / 2;

       while (k <= j) {
         j -= k;
         k /= 2;
        }

       j += k;
    }
    // disposing temporary arrays
	free(tempR);
	free(tempI);
}


void transposeTDSignal1(void) {
   unsigned int i, j, n, BitNum, newIndex;
   unsigned int AndOpBitL, AndOpBitH, BitH, BitL;
   double temp;
   // copying x[i] into ReX[i] and setting ImX to 0s
   for (i=0; i<N; i++) {
		ReX[i] = x[i];
		ImX[i] = 0.0;
	}
   // transposing the time domain signal
   // calculating number of bits
   BitNum = (unsigned int)(log(N)/log(2));
   // iterating from the second to the N-1th element (1st and Nnth are not swapped) 
   for (i=1; i<N-2; i++) {
      // setting new index to 0
      newIndex = 0;
	  // mask for the low bit
	  AndOpBitL = 1;
	  // mask for the high bit
	  AndOpBitH = N/2;
	  // iterating from the first bit to the middle
      for (j=0; j<BitNum/2+1; j++) {
      	// reversing low bit
      	BitH = (i & AndOpBitL) << (BitNum-1-2*j);
		// reversing high bit
		BitL = (i & AndOpBitH) >> (BitNum-1-2*j);
      	// adding both bits to the new index
      	newIndex |= BitH | BitL;
		// shifting low bit mask to the left
		AndOpBitL *= 2;
		// shifting high bit mask to the right
		AndOpBitH /= 2;
	  }
	  // swapping array elements
	  if (newIndex>i) {
	  	temp = ReX[newIndex];
		ReX[newIndex] = ReX[i];
		ReX[i] = temp;
	  }
   }
 
}

void transposeFDSignal1(void) {
   unsigned int i, j, n, BitNum, newIndex;
   unsigned int AndOpBitL, AndOpBitH, BitH, BitL;
   double tempR, tempI;
   
   // transposing the frequency domain signal
   // calculating number of bits
   BitNum = (unsigned int)(log(N)/log(2));
   // iterating from the second to the N-1th element (1st and Nnth are not swapped) 
   for (i=1; i<N-2; i++) {
      // setting new index to 0
      newIndex = 0;
	  // mask for the low bit
	  AndOpBitL = 1;
	  // mask for the high bit
	  AndOpBitH = N/2;
	  // iterating from the first bit to the middle
      for (j=0; j<BitNum/2+1; j++) {
      	// reversing low bit
      	BitH = (i & AndOpBitL) << (BitNum-1-2*j);
		// reversing high bit
		BitL = (i & AndOpBitH) >> (BitNum-1-2*j);
      	// adding both bits to the new index
      	newIndex |= BitH | BitL;
		// shifting low bit mask to the left
		AndOpBitL *= 2;
		// shifting high bit mask to the right
		AndOpBitH /= 2;
	  }
	  // swapping array elements
	  if (newIndex>i) {
	  	tempR = ReX[newIndex];
		ReX[newIndex] = ReX[i];
		ReX[i] = tempR;
		tempI = ImX[newIndex];
		ImX[newIndex] = ImX[i];
		ImX[i] = tempI;
	  }
   }
 
}
   

void computeFFT1(void) {

  int l, fd, levels, j, k;
  unsigned int Nl_1, Nl, indE, indO;
  
  double ReL, ImL, ReH, ImH;
  // computing number of decomposition levels (stages)
  levels = (unsigned int)(log(N)/log(2));
  // Number of frequcny domain points per partial transform in level - l+1
  Nl_1 = 1;
  // number of frequency domain points per partial transform in level - l
  Nl = 2;
  // iterating from the last level to the top, counting backwards
  for (l = 0; l < levels; l++) { 
    // iteration for each frequency domain (fd) in the current level
  	for (fd = 0; fd < N/Nl; fd++) 
        for (k = 0; k < Nl_1; k++) {
           // index of the even frequency domain value 
           indE = fd * 2 * Nl_1 + k;
		   // index of the odd frequency domain value
           indO = (fd * 2 +1)* Nl_1 + k;
           
           // calculating ReX[k] and imX[k] 
           ReL = ReX[indE] + ReX[indO] * cos(2 * PI * k / Nl) + ImX[indO] * sin(2 * PI * k / Nl);
           ImL = ImX[indE] + ImX[indO] * cos(2 * PI * k / Nl) - ReX[indO] * sin(2 * PI * k / Nl);
           // calculating ReX[k+N/2] and ImX[k+N/2]
           ReH = ReX[indE] - ReX[indO] * cos(2 * PI* k / Nl) - ImX[indO] * sin(2 * PI * k / Nl);
           ImH = ImX[indE] - ImX[indO] * cos(2 * PI * k / Nl) + ReX[indO] * sin(2 * PI * k / Nl);

           /* storing values (overwriting old Rex[k] and ImX[k]
		     of the even (indE) and odd (indO) transform values) */
		   ReX[indE] = ReL;
		   ImX[indE] = ImL;
		   ReX[indO] = ReH;
		   ImX[indO] = ImH;
		  
        }
    Nl_1 *= 2;
    Nl *= 2;       
  }
  // normalizing frequency domain
   for (k = 0; k < N; k++) {
       ReX[k] /= (1.0*N);
       ImX[k] /= (1.0*N);
	   // calculating magnitude
	   Magnitudes[k] = sqrt(ReX[k]*ReX[k]+ImX[k]*ImX[k]);
   }        
}

void computeInverseFFT1(void) {

  int l, fd, levels, j, k;
  unsigned int Nl_1, Nl, indE, indO;
  double ReL, ImL, ReH, ImH;
  // Number of frequcny domain points per partial transform in level - l+1
  Nl_1 = 1;
  // number of frequency domain points per partial transform in level - l
  Nl = 2;
  // iterating from the last level to the top, counting backwards
  levels = (unsigned int)(log(N)/log(2));
  // iterating from the last level to the top
  for (l = 0; l < levels; l++) { 
    // iteration for each frequency domain (fd) in the current level
  	for (fd = 0; fd < N/Nl; fd++) 
        // computation loop (runs for half the size of the frequency domain)
        for (k = 0; k < Nl_1; k++) {
           // index of the even frequency domain value 
           indE = fd * 2 * Nl_1 + k;
		   // index of the odd frequency domain value
           indO = (fd * 2 +1)* Nl_1 + k;
           
           // calculating ReX[k] and imX[k] 
           ReL = ReX[indE] + ReX[indO] * cos(2 * PI * k / Nl) - ImX[indO] * sin(2 * PI * k / Nl);
           ImL = ImX[indE] + ImX[indO] * cos(2 * PI * k / Nl) + ReX[indO] * sin(2 * PI * k / Nl);
           // calculating ReX[k+N/2] and ImX[k+N/2]
           ReH = ReX[indE] - ReX[indO] * cos(2 * PI* k / Nl) + ImX[indO] * sin(2 * PI * k / Nl);
           ImH = ImX[indE] - ImX[indO] * cos(2 * PI * k / Nl) - ReX[indO] * sin(2 * PI * k / Nl);

           /* storing values (overwriting old Rex[k] and ImX[k]
		     of the even (indE) and odd (indO) transform values) */		   
		   ReX[indE] = ReL;
		   ImX[indE] = ImL;
		   ReX[indO] = ReH;
		   ImX[indO] = ImH;
        }
  Nl *= 2;
  Nl_1 *= 2;
  }   
  
}


void computeFFT2() {
  int Nl_1, Nl, i1, i, k, l, levels;
  double u1, u2, t1, t2, z;
  double ca;
  double sa;
  //ca and sa contain the cosine and sine
  ca = -1.0;
  sa = 0.0;
  Nl_1 = Nl = 1;
  levels = (unsigned int)log(N)/log(2); 
  for (l = 0; l < levels; l++) {
     // l+1-level DFT length
     Nl_1 = Nl;
	 // l-level DFT length
     Nl *= 2;
     u1 = 1.0;
     u2 = 0.0;
	 // for each position-k inside the small DFTs
     for (k = 0; k < Nl_1; k++) {
        // calculating and storing ReX[k] ands ImX[k] for ALL DFTs in level-l
        for (i = k; i < N; i += Nl) {
           i1 = i + Nl_1;
           t1 = u1 * ReX[i1] - u2 * ImX[i1];
           t2 = u1 * ImX[i1] + u2 * ReX[i1];
           ReX[i1] = ReX[i] - t1;
           ImX[i1] = ImX[i] - t2;
           ReX[i] += t1;
           ImX[i] += t2;
         }
	 // computing coefficients for the next step
     z = u1 * ca - u2 * sa;
     u2 = u1 * sa + u2 * ca;
     u1 = z;
     }
	 // finding new cosine and sine
     sa = sqrt((1.0 - ca) / 2.0);
     ca = sqrt((1.0 + ca) / 2.0);
    // ****** included in forward FFT *****             
    sa = -sa;
    
   }
   // normalizing frequency domain
   for (i = 0; i < N; i++) {
       ReX[i] /= (1.0*N);
       ImX[i] /= (1.0*N);
	   Magnitudes[i] = sqrt(ReX[i]*ReX[i]+ImX[i]*ImX[i]);
   } 
}

void computeInverseFFT2() {
  int Nl_1, Nl, i1, i, k, l, levels;
  double u1, u2, t1, t2, z;
  double ca;
  double sa;
  //ca and sa contain the cosine and sine
  ca = -1.0;
  sa = 0.0;
  Nl_1 = Nl = 1;
  levels = (unsigned int)log(N)/log(2); 
  for (l = 0; l < levels; l++) {
     // l+1-level DFT length
     Nl_1 = Nl;
	 // l-level DFT length
     Nl *= 2;
     u1 = 1.0;
     u2 = 0.0;
	 // for each position-k inside the small DFTs
     for (k = 0; k < Nl_1; k++) {
        // calculating and storing ReX[k] and ImX[k] for ALL DFTs in level-l
        for (i = k; i < N; i += Nl) {
           i1 = i + Nl_1;
           t1 = u1 * ReX[i1] - u2 * ImX[i1];
           t2 = u1 * ImX[i1] + u2 * ReX[i1];
           ReX[i1] = ReX[i] - t1;
           ImX[i1] = ImX[i] - t2;
           ReX[i] += t1;
           ImX[i] += t2;
         }
	 // computing coefficients for the next step
     z = u1 * ca - u2 * sa;
     u2 = u1 * sa + u2 * ca;
     u1 = z;
     }
	 // finding new cosine and sine
     sa = sqrt((1.0 - ca) / 2.0);
     ca = sqrt((1.0 + ca) / 2.0);
    // **********************************
   }
    
}