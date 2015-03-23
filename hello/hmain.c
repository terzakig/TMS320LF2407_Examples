// Turning an a pin. Something like a "hello world" program...
//
// George Terzakis 2009
//
// From the book: "Introduction to C programming with the TMS320LF2407 DSP Controller"

#include "DSP24_Gpio.h"
#include "DSP24_DefaultISR.h"

extern void initSystem(void);


void main() {
     
     int i;
     
     initSystem();     

	 MCRAbits->bit.SCITXD_GPIOA0=0; // A0 is General I/O
	 MCRAbits->bit.SCITXD_GPIOA0=0; // A1 is General I/O
	 PADATDIRbits->bit.A0DIR=1;     // A0 is Output
	 PADATDIRbits->bit.A1DIR=1;     // A1 is output
	 
	 while (1) {
		 for(i=1;i<=1000;i++); // delay loop
	     	 
		 PADATDIRbits->bit.IOPA0=(PADATDIRbits->bit.IOPA0==1) ? 0 : 1; // Toggle A0
		 PADATDIRbits->bit.IOPA1=(PADATDIRbits->bit.IOPA1==1) ? 0 : 1; // Toggle A1
	 }
}
     

