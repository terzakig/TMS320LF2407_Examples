// **********************************
// Example on using the ADC of the 2407
// George Terzakis 2009

#include "DSP24_SysFunc.h"


extern unsigned int bufindex;
extern unsigned int adc_buf[16];

/****************************** MAIN ROUTINE ***************************/
void main(void)
{
	unsigned int ind;
	initSystem(noPWM,noPWM,noPWM,noPWM,
				noCAN, noSPI, noSCI, noCAP, noCAP,
				noCAP, noCAP, noCAP, noCAP, 1, 4);  
	initPWMEVA(50, 0.25, 0.5, 0.6);
	
	bufindex=0;
	
	for (ind=0;ind<16;ind++) 
		adc_buf[ind]=3;
    initADC(ADCsample16);

	asm(" CLRC INTM"); 
    while(1);

}



		
		