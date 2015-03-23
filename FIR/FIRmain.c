// Creating and applying FIR filters to trails of pulses. The resulting signal becomes available by means of a DAC
//
// George Terzakis 2009
//
// From the book: "Introduction to C programming with the TMS320LF2407 DSP Controller"

#include "DSP24_Sys.h"
#include "Globals.h"
#include "Peripherals.h"


void main() {
  unsigned int wrd, temp, ADCinput = TRUE, DispVirtualInput = FALSE;
  double sin1, sin2, inp;
 
  initSystem();
  initVars(f_WSinc_LowPass);
  initADC();
  
  initTimer1();
  
  initSPI();
  initIO();
  

  // enable global interrupt switch
  asm(" CLRC INTM");
  // main loop
  while (1) {	
	if (flagDoOutput == TRUE) {
	   if (ADCinput==TRUE) { // real sampled input (timer compare pin)
	     // retrieving ONLY the first ADC result
         temp = *RESULT / 64;
         // scaling temp and storing in x[]
	     inp = 1.0*temp/1023.0;
	   }
	   else {// sinusoidal sum input (virtual input)
	     sin1 = 0.6*sin(2*PI*TDindex/40);
	     sin1 = (sin1 < 0) ? -sin1 : sin1;
		
	     sin2 = 0.4*sin(150*PI*TDindex/40);
	     sin2 = (sin2 < 0) ? -sin2 : sin2;

		 inp = sin1 + sin2;
	    }
	   if (DispVirtualInput == TRUE) {
	      wrd = (unsigned int)(1023.0*inp);
		  wrd = wrd << 2;
		  sendWordSPI(wrd);
	   }
	     else 
	   		   //convolving
	   		   shiftConvolve(inp);
	   
       // Recycling index for the virtual sinusoidal input 	
	   TDindex = (TDindex - 1 <0) ? WAVE_LEN - 1 : TDindex - 1;
	   
	   // reset sequencer
	   ADCTRL2bits->bit.RSTSEQ1STRTCAL = 1;
	   // clear process flag
	   flagDoOutput = FALSE;
       // restart sequencer
	   ADCTRL2bits->bit.SOCSEQ1 = 1;
	   
	}
  }

}