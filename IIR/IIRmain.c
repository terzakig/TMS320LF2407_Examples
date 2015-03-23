// Creating an IIR filter and applying it to a trail of pulses. Results are then directed to a DAC (via the SPI) and the filtered signal is obtained in its analog form.
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
  initVars(f_ButterHighPassOrd2);
  initADC();
  
  initTimer1();
  
  initSPI();
  initIO();
  

  // enable global interrupt switch
  asm(" CLRC INTM");
  // main loop
  while (1) {	
	if (flagDoOutput == TRUE) {
	   if (ADCinput==TRUE) { // real sampled input (timer compare pinn)
         // scaling temp and storing in x[]
		 // clearing sign extension bit
		 asm(" CLRC SXM");
		 temp = *RESULT;
		 // shifting right
		 temp = temp >> 6;
		 // scaling ADC input
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
	   		   //compute IIR output
	   		   calculateOutput(inp);
	   
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