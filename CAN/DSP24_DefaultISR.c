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


interrupt void ADCINTHP_ISR() {

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


interrupt void RXINTLP_ISR(void) {
asm ("NOP");
}

interrupt void TXINTLP_ISR(void) {

asm("  NOP");
}

interrupt void SPIINTLP_ISR(void) {

asm(" NOP");

}

interrupt void CANMBINTHP_ISR(void) {
  unsigned int MsgPending0, TransmitAcknowledge2;
  unsigned int mbox0A, mbox0B;

  TransmitAcknowledge2 = TCRbits->bit.TA2;

  MsgPending0 = RCRbits->bit.RMP0;
   
  // clearing acknowledge flag in TCR
  TCRbits->bit.TA2 = 1;
  // clearing interrupt flag
  CAN_IFRbits->bit.MIF2 = 1;
  
  mbox0A = *MBX0A;
  mbox0B = *MBX0B;
  asm (" NOP");

}


   
interrupt void CANERINTHP_ISR(void) {  
  asm(" NOP");
}





interrupt void INT1_GISR(void){
 
    unsigned int peripheral; 

	asm(" SETC INTM");
     peripheral = *PIVR;
	asm(" CLRC INTM");
	
	switch (peripheral) {
		case 0x0004: // ADC Mailbox High Priority interrupt
				    ADCINTHP_ISR();
				  	break;
		case 0x0040: // CAN mailbox High Priority interrupt
					 CANMBINTHP_ISR();
					 break;
		case 0x0041: // CAN Error High Priority Interrupt
		             CANERINTHP_ISR();
		             break;

	}
	// reset the core INT1 flag by writing a "1" in bit 0 of IFR
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
}
