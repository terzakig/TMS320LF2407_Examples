#include "DSP24_DefaultISR.h"


// Timer 1 Period interrupt
interrupt void T1PINT_ISR(void) {
  EVAIFRAbits->bit.T1PINT=1;
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

// Timer 2 Overflow interrupt
interrupt void T1OFINT_ISR(void) {
 asm(" NOP");
}

// Timer 2 Period interrupt
interrupt void T2PINT_ISR(void) {

asm(" NOP");

}
// Timer 2 Compare interrupt
interrupt void T2CINT_ISR(void) {

asm(" NOP");
}
// Timer 2 Underflow interrupt
interrupt void T2UFINT_ISR(void) {
asm(" NOP");	
}

// Timer 2 Overflow interrupt
interrupt void T2OFINT_ISR(void) {
 asm(" NOP");
}

// Timer 3 Period interrupt
interrupt void T3PINT_ISR(void) {
  unsigned int wrd;
  // clearing interrupt flag
  EVBIFRAbits->bit.T3PINT = 1;
  PADATDIRbits->bit.IOPA3 = 0;
  
 
}
// Timer 3 Compare interrupt
interrupt void T3CINT_ISR(void) {

asm(" NOP");
}
// Timer 3 Underflow interrupt
interrupt void T3UFINT_ISR(void) {
asm(" NOP");	
}

// Timer 3 Overflow interrupt
interrupt void T3OFINT_ISR(void) {
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


interrupt void ADCINTHP_ISR(void) {

asm(" NOP");

}

interrupt void ADCINTLP_ISR(void) {
	unsigned int temp;
	int i;
	
    
	if (EnableDFT == FALSE) {
    	for (i=0; i<16; i++) { 
    	   temp = *(RESULT+i) / 64;
		   x[TDindex] = 1.0*temp/1023.0;
		   TDindex++;
		}
		if (TDindex == N) {
		   TDindex = 0;
		   EnableDFT = TRUE;
		 }
	}
	// clearing interrupt flag
	ADCTRL2bits->bit.INTFLAGSEQ1 = 1;
	// reset sequencer
	ADCTRL2bits->bit.RSTSEQ1STRTCAL = 1;
	// start sequencer
	ADCTRL2bits->bit.SOCSEQ1 = 1;
}

// SCI low priority RX interrupt 
interrupt void RXINTLP_ISR(void) {
asm ("NOP");
}

// SCI low priority TX interrupt
interrupt void TXINTLP_ISR(void) {

asm("  NOP");
}

// SPI low priority interrupt
interrupt void SPIINTLP_ISR(void) {

asm(" NOP");

}

// CAN mailbox high priority interrupt
interrupt void CANMBINTHP_ISR(void) {

asm (" NOP");
}

// CAN error high priority interrupt
interrupt void CANERINTHP_ISR(void) {
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
		case 0x0040: // CAN mailbox High Priority interrupt
					 CANMBINTHP_ISR();
					 break;
		case 0x0041: // CAN Error High Priority Interrupt
		             CANERINTHP_ISR();
		             break;
	}
} 


interrupt void INT2_GISR(void) {// GISR for all INT2 level peripherals
    
	unsigned int peripheral;

	asm(" SETC INTM");
    peripheral=*PIVR;

	// reset the core INT2 flag by writing a "1" in bit 1
    *IFR|=2; 
	
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
	   case 0x002F: // Timer 3 period
				    T3PINT_ISR();
					break;
	   case 0x0030: // Timer 3 compare
					T2CINT_ISR();
					break;
	   case 0x0031: // Timer 3 Underflow
	   			    T3UFINT_ISR();
	   			    break;
	   case 0x0032: // Timer 3 Overflow
	                T3OFINT_ISR();
	                break; 
	   default: break;	
	}
	// reset the core INT1 flag by writing a "1" in bit 1 of IFR
    *IFR|=1;
 
}

interrupt void INT3_GISR(void){
	unsigned int peripheral;

	asm(" SETC INTM");
    	peripheral=*PIVR;
	asm(" CLRC INTM");
	 
	
	switch (peripheral) {
		
		case 0x002B: // Timer 2 Period
					 T2PINT_ISR();
					 break;
		case 0x002C: // Timer 2 Compare
					 T2CINT_ISR();
					 break;
		case 0x002D: // Timer 2 Underflow
					 T2UFINT_ISR();
					 break;
		case 0x002E: // Timer 2 Overflow
					 T2OFINT_ISR();
					 break;
		case 0x0033: // Capture 1 
		             CAP1INT_ISR();
				     break;
	   	case 0x0034: // Capture 2
		             CAP2INT_ISR();
				     break;
		default: break;
	}				   
	// reset the core INT3 flag by writing a "1" in bit 2
    *IFR|=4;
} 

interrupt void INT4_GISR(void){
} 

interrupt void INT5_GISR(void) {
unsigned int peripheral;
	 

	asm(" SETC INTM");
    peripheral=*PIVR;
	asm(" CLRC INTM");
	
	switch (peripheral) {
	
	   case 0x0006: // SCI Receive 
		           RXINTLP_ISR();
				   break;
	   case 0x0007: // SCI Transmit
		           TXINTLP_ISR();
				   break;
	   case 0x0005: // SPI interrupt
					SPIINTLP_ISR();
					break;
	   default: break;	
	}
	// reset INT5 flag by writing a "1" in bit 4 of IFR 
    *IFR|=0x10;
} 

interrupt void INT6_GISR(void) {
    unsigned int peripheral;
 

	asm(" SETC INTM");
    peripheral=*PIVR;
	asm(" CLRC INTM");
	
	switch (peripheral) {
	
	   case 0x0004: // ADC low priority 
		           ADCINTLP_ISR();
				   break;
	   
	   default: break;	
	}
   // reset INT6 flag by writing a "1" in bit 5 of IFR 
    *IFR|=0x20;	 
}
