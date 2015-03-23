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
unsigned int results[16];
int i;

// copying results
for (i=0; i<16; i++) 
	results[i] = *(RESULT+i) / 64;
 

// clearing interrupt flag
ADCTRL2bits->bit.INTFLAGSEQ1 = 1;

PADATDIRbits->bit.IOPA0 = (PADATDIRbits->bit.IOPA0 == 0) ? 1 : 0; 
asm(" NOP");

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
