#include "DSP24_DefaultISR.h"

// Timer 1 Period interrupt
interrupt void T1PINT_ISR(void) {

  EVAIFRAbits->bit.T1PINT = 1; // Clear Period Interrupt flag
  asm(" NOP");
}
// Timer 1 Compare interrupt
interrupt void T1CINT_ISR(void) {

  EVAIFRAbits->bit.T1CINT = 1; // Clear Compare Interrupt flag
  asm(" NOP");
}
// Timer 1 Underflow interrupt
interrupt void T1UFINT_ISR(void) {

  EVAIFRAbits->bit.T1UFINT = 1; // Clear UnderFlow Interrupt Flag
  asm(" NOP");	
}

// Timer 1 Overflow interrupt
interrupt void T1OFINT_ISR(void) {

  EVAIFRAbits->bit.T1OFINT = 1; // Clear OverFlow Interrupt Flag
  asm(" NOP");
}

// Compare 1 Interrupt
interrupt void CMP1INT_ISR(void) {
  EVAIFRAbits->bit.CMP1INT=1; // Clear Compare 1 interrupt flag
  asm(" NOP");
}


interrupt void INT1_GISR(void){
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
