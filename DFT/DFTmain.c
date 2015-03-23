// Computing the FFT of a periodic pulse and feeding it to a DAC (produces a beautiful Dirichlet kernel depiction on the oscilloscope)
//
// George Terzakis 2009
//
// From the book: "Introduction to C programming with the TMS320LF2407 DSP Controller"

#include "Globals.h"
#include "DSP24_Sys.h"
#include "Peripherals.h"



void main() {

  unsigned int METHOD = mFFT, i;

  initSystem();
  initVars();  
  initTimer1();
  initADC();
  initSPI();
  
  initIO();
  
  // enable global interrupt switch
  asm(" CLRC INTM");

  while (1) {
      
	   if (EnableDFT == TRUE) {
	   	  if (METHOD == mDFT) // Computing DFT
       		computeDFT();
		else {
		    // transposing time domain
			transposeTDSignal1();
			computeFFT1();
			//transposeFDSignal1();
			//computeInverseFFT1(); 
		 }
	   // dump the signal 1000 times
       for (i=0; i<1000; i++)
	    dumpSignal();
		//dumpTDSignal();
	   EnableDFT = FALSE;
	 }	  
  }


}
