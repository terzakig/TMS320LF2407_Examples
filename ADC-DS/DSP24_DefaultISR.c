#include "DSP24_DefaultISR.h"


// Timer 1 Period interrupt
interrupt void T1PINT_ISR(void) {
  
  asm(" NOP");
  
}
// Timer 1 Compare interrupt
interrupt void T1CINT_ISR(void) {

asm(" NOP");
}
// Timer 1 Underflow interrupt
interrupt void T1UFINT_ISR(void) {
asm(" NOP");	
}

// Timer 1 Overflow interrupt
interrupt void T1OFINT_ISR(void) {
 asm(" NOP");
}

// Compare 1 Interrupt
interrupt void CMP1INT_ISR(void) {
asm(" NOP");
}


// Capture 1 Interrupt
interrupt void CAP1INT_ISR(void) {
 asm(" NOP");
}

// Capture 2 Interrupt
interrupt void CAP2INT_ISR(void) {
 asm(" NOP");
}

interrupt void ADCINTHP_ISR() {
  unsigned int resultSEQ1[8], resultSEQ2[8], i;

  // Checking for a Sequencer 1 End of Conversion
  if (ADCTRL2bits->bit.INTFLAGSEQ1 == 1) {
      // Sequencer 1 results
	  for (i=0; i<4; i++) 
	  	resultSEQ1[i] = *(RESULT+i) / 64;
	  // clearing the flag
	  ADCTRL2bits->bit.INTFLAGSEQ1 = 1;
	  
      // resetting sequencer 1 to a pre-triggered initial state 
      ADCTRL2bits->bit.RSTSEQ1STRTCAL = 1;
      // starting Sequencer 2
	  ADCTRL2bits->bit.SOCSEQ2 = 1;
       
	  
  }

  // Checking for a Sequencer 2 End of Conversion
  if ( ADCTRL2bits->bit.INTFLAGSEQ2 ==1) {
      // Sequencer 1 results
	  for (i=8; i<12; i++) 
	  	resultSEQ2[i] = *(RESULT+i) / 64;
	  // clearing the flag
	  ADCTRL2bits->bit.INTFLAGSEQ2 = 1;

      // Resetting Sequencer 2 into a pre-triggered initial state
	  ADCTRL2bits->bit.RSTSEQ2 = 1;
	  // starting sequencer 1
	  ADCTRL2bits->bit.SOCSEQ1 = 1;
  }



}


interrupt void INT1_GISR(void){
 
    unsigned int peripheral;
	 
	asm(" SETC INTM");
     peripheral = *PIVR;
	asm(" CLRC INTM");
	
	switch (peripheral) {
		case 0x0004: // ADC High Priority interrupt
					ADCINTHP_ISR();
					break;
	}
	// reset the core INT1 flag by writing a "1" in bit 1 of IFR
    *IFR|=1;
} 


interrupt void INT2_GISR(void) {// GISR for all INT2 level peripherals
    
	unsigned int peripheral;
	 

	asm(" SETC INTM");
    peripheral=*PIVR;
	asm(" CLRC INTM");
	
	switch (peripheral) {
	
	   case 0x0027: // Timer 1 period
		           T1PINT_ISR();
				   break;
	   case 0x0028: // Timer 1 Compare
		           T1CINT_ISR();
				   break;
	   case 0x0029: // Timer 1 UnderFlow
		           T1UFINT_ISR();
				   break;
	   case 0x002A: // Timer OverFlow
		           T1OFINT_ISR();
				   break;
	   case 0x0021: // Compare 1
				   CMP1INT_ISR();
				   break;
	   default: break;	
	} 
	// reset the core INT2 flag by writing a "1" in bit 1
    *IFR|=2;
}

interrupt void INT3_GISR(void){
} 

interrupt void INT4_GISR(void){
} 

interrupt void INT5_GISR(void) {
} 

interrupt void INT6_GISR(void) {
}
