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
  unsigned int test, test2;
  
  test=CAPFIFOAbits->bit.CAP1FIFOSTAT;
  test2=CAPFIFOAbits->bit.CAP2FIFOSTAT;
  EVAIFRAbits->bit.CMP1INT=1; // Clear Compare 1 interrupt flag
  asm(" NOP");
}

// Capture 1 Interrupt
interrupt void CAP1INT_ISR(void) {
 unsigned int status, top, bottom;
 status=CAPFIFOAbits->bit.CAP1FIFOSTAT;
 if (status==1) // one reading in queue
     top = *CAP1FIFO;
 else if (status>1) { // 2 or more readings in queue
     top = *CAP1FIFO; // reading newest detection
     bottom = *CAP1FIFO; // reading previous detection
  }
 EVAIFRCbits->bit.CAP1INT=1; // clear cap1 interrupt flag
 asm(" NOP");
}

// Capture 2 Interrupt
interrupt void CAP2INT_ISR(void) {
 unsigned int status,top, bottom;
 status=CAPFIFOAbits->bit.CAP2FIFOSTAT;
 if (status==1) // 1 reading in queue
    top = *CAP2FIFO;
 else if (status>1) { // 2 or more readings in queue 
    top = *CAP2FIFO; // reading newest detection
	bottom = *CAP2FIFO; // reading previous detection
  }
 EVAIFRCbits->bit.CAP2INT=1; // clear cap2 interrupt flag
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
	unsigned int peripheral;

	asm(" SETC INTM");
    peripheral=*PIVR;
	asm(" CLRC INTM");
	
	switch (peripheral) {
	
	   case 0x0033: // Capture 1 
		           CAP1INT_ISR();
				   break;
	   case 0x0034: // Capture 2
		           CAP2INT_ISR();
				   break;
	   default: break;	
	} 
	// reset INT4 flag by writing a "1" in bit 3 of IFR 
    *IFR|=8; 

} 

interrupt void INT5_GISR(void) {
} 

interrupt void INT6_GISR(void) {
}
