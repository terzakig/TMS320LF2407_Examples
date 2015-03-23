
#include "DSP24_DefaultIsr.h"
#include "DSP24_Core.h"
#include "f2407_c.h"
#include "DSP24_Ev.h"
#include "DSP24_Adc.h"
#include "DSP24_Gpio.h"

unsigned int adc_buf[16]; 
unsigned int bufindex;
// Now here comes all Specific ISRs...
// 1) Power drvive Protection Interrupt pin A
interrupt void PDPINTA_ISR(void) {

asm(" CLRC INTM");
}
// 2) Power Drive Protection interrupt pin B
interrupt void PDPINTB_ISR(void) {

}
// 3) ADC interrupt in high priority
interrupt void ADCINT_HP_ISR(void) {
    unsigned int i;
	ADCTRL2bits->bit.INTFLAGSEQ2=1; //clearing the SEQ2 interrupt flag
    ADCTRL2bits->bit.INTFLAGSEQ1=1; // Clear SEQ1 int flag
    asm(" CLRC SXM"); // clearing sign extensions for shifting
    
    adc_buf[bufindex]=*(RESULT0+bufindex)>>6;
	
	asm (" SETC SXM"); // restoring sign extension bit 		
	
	bufindex=(bufindex==15) ? 0 : bufindex+1;

	// Toggling GPIO C2 to indicate an ADC interrupt
	// for experimentation and time measurement
	IODIRDATCbits->bit.IOPC2=(IODIRDATCbits->bit.IOPC2==0) ? 1 : 0;

asm(" CLRC INTM");
}

// 4) External pin1 interrupt in high priority
interrupt void XINT1_HP_ISR(void) {

asm(" CLRC INTM");
}
// 5) External pin2 interrupt in high priority
interrupt void XINT2_HP_ISR(void) {

}
// 6) SPI interrupt in high priority
interrupt void SPIINT_HP_ISR(void) {

asm(" CLRC INTM");
}
// 7) SCI Receive (Rx) interrupt in high priority
interrupt void RXINT_HP_ISR(void) {

asm(" CLRC INTM");
}
// 8) SCI Transmit (Tx) interrupt in high priority
interrupt void TXINT_HP_ISR(void) {

asm(" CLRC INTM");
}
// 9) CAN mailbox interrupt in high priority
interrupt void CANMBINT_HP_ISR(void) {

asm(" CLRC INTM");
}
// 10) CAN Error interrupt in high priority
interrupt void CANERINT_HP_ISR(void) {

asm(" CLRC INTM");
}


// 1) Compare 1 Interrupt
interrupt void CMP1INT_ISR(void) {

asm(" CLRC INTM");
}
// 2) Compare 2 interrupt
interrupt void CMP2INT_ISR(void) {

asm(" CLRC INTM");
}
// 3) Compare 3 Interrupt
interrupt void CMP3INT_ISR(void) {

asm(" CLRC INTM");
}
// 4) Timer 1 Period interrupt
interrupt void T1PINT_ISR(void) {

asm(" CLRC INTM");
}
// 5) Timer 1 Compare interrupt
interrupt void T1CINT_ISR(void) {

asm(" CLRC INTM");
}
// 6) Timer 1 Underflow interrupt
interrupt void T1UFINT_ISR(void) {
  	EVAIFRAbits->bit.T1UFINT = 1;// *EVIFRA=*EVAIFRA & 0x0200;
//	if(*PIVR==0x0029)             /*time1 overbelow interrupt*/
//	{
		
		*CMPR1= (int)(3000*0.01);	
		*CMPR2= 3000*0.6;
		*CMPR3= 3000*0.75;
//	}  
asm(" CLRC INTM");
}
// 7) Timer 1 Overflow interrupt
interrupt void T1OFINT_ISR(void) {

asm(" CLRC INTM");
}
// 8) Compare 4 interrupt
interrupt void CMP4INT_ISR(void) {

asm(" CLRC INTM");
}
// 9) Compare 5 interrupt
interrupt void CMP5INT_ISR(void) {

asm(" CLRC INTM");
}
// 10) Compare 6 interrupt
interrupt void CMP6INT_ISR(void) {

asm(" CLRC INTM");
}
// 11) Timer 3 Period interrupt
interrupt void T3PINT_ISR(void) {

asm(" CLRC INTM");
}
// 12) Timer 3 Compare interrupt
interrupt void T3CINT_ISR(void) {

asm(" CLRC INTM");
}
// 13) Timer 3 Underflow interrupt
interrupt void T3UFINT_ISR(void) {

asm(" CLRC INTM");
}
// 14) Timer 3 Overflow interrupt
interrupt void T3OFINT_ISR(void) {

asm(" CLRC INTM");
}


//1) Timer 2 Period interrupt
interrupt void T2PINT_ISR(void) {

asm(" CLRC INTM");
}
//2) Timer 2 Compare interrupt
interrupt void T2CINT_ISR(void) {

asm(" CLRC INTM");
}
//3) Timer 2 Underflow interrupt
interrupt void T2UFINT_ISR(void) {

asm(" CLRC INTM");
}
//4) Timer 2 Overflow interrupt
interrupt void T2OFINT_ISR(void) {

asm(" CLRC INTM");
}
//5) Timer 4 Period interrupt
interrupt void T4PINT_ISR(void) {

T4CONbits->bit.TENABLE=0;

asm(" CLRC INTM");
}
//6) Timer 4 Compare interrupt
interrupt void T4CINT_ISR(void) {

asm(" CLRC INTM");
}
//7) Timer 4 Underflow interrupt
interrupt void T4UFINT_ISR(void) {

asm(" CLRC INTM");
}
//8) Timer 4 Overflow interruopt
interrupt void T4OFINT_ISR(void) {

asm(" CLRC INTM");
}


//1) Capture 1 interrupt
interrupt void CAP1INT_ISR(void) {

asm(" CLRC INTM");
}
//2) Capture 2 interrupt
interrupt void CAP2INT_ISR(void) {

asm(" CLRC INTM");
}
//3) Capture 3 interrupt
interrupt void CAP3INT_ISR(void) {

asm(" CLRC INTM");
}
//4) Capture 2 interrupt
interrupt void CAP4INT_ISR(void) {

asm(" CLRC INTM");
}
//5) Capture 5 interrupt
interrupt void CAP5INT_ISR(void) {

asm(" CLRC INTM");
}
//6) Capture 6 interrupt
interrupt void CAP6INT_ISR(void) {

asm(" CLRC INTM");
}


//1) SPI interrupt in low priority
interrupt void SPIINT_LP_ISR(void) {

asm(" CLRC INTM");
}
//2) SCI receive (RX) interrupt in low priority
interrupt void RXINT_LP_ISR(void) {

asm(" CLRC INTM");
}
//3) SCI Transmit (Tx) interrupt in low priority
interrupt void TXINT_LP_ISR(void) {

asm(" CLRC INTM");
}
//4) CAN mailbox interrupt in low priority
interrupt void CANMBINT_LP_ISR(void) {

asm(" CLRC INTM");
}
//5) CAN Error interrupt in low priority
interrupt void CANERINT_LP_ISR(void) {

asm(" CLRC INTM");
}


//1) ADC interrupt in low priority
interrupt void ADCINT_LP_ISR(void) {

asm(" CLRC INTM");
}
//2) External pin1 interrupt in low priority
interrupt void XINT1_LP_ISR(void) {

asm(" CLRC INTM");
}
//3) External pin 2 interrupt in low priority
interrupt void XINT2_LP_ISR(void) {

asm(" CLRC INTM");
}





// ***************INT1 GISR **********************

interrupt void INT1_GISR(void) { // GISR for all INT1 level peripherals

	unsigned int peripheral;
	// resetting the core INT1 flag
	IFRbits->bit.INT1FLAG=1;

	asm(" SETC INTM");
    peripheral=*PIVR;
	

	switch (peripheral) {
	   case 0x0020: //PDPINTA
		           PDPINTA_ISR();
		           break; 
	   case 0x0019: // PDPINTB
			       PDPINTB_ISR();
			       break; 	 
	   case 0x0004: //ADC high priority
		           ADCINT_HP_ISR();
				   break;
	   case 0x0001: //XINT1 high priority
			       XINT1_HP_ISR();
				   break;
	   case 0x0011: // XINT2 high priority
		           XINT2_HP_ISR();
				   break;
	   case 0x0005: // SPIINT h.p.
		           SPIINT_HP_ISR();
				   break;
	   case 0x0006: // SCI RX hp
		           RXINT_HP_ISR();
				   break;
	   case 0x0007: // SCI TX hp
		           TXINT_HP_ISR();
				   break;
	   case 0x0040: // CAN MB hp
		           CANMBINT_HP_ISR();
				   break;
	   case 0x0041: // CAN error hp
		           CANERINT_HP_ISR();
				   break;
	} 

    
	
}	


// ***************INT 2 GISR**********************

interrupt void INT2_GISR(void) {// GISR for all INT2 level peripherals
    
	unsigned int peripheral;
	// reset the core INT2 flag
    IFRbits->bit.INT2FLAG=1;

	asm(" SETC INTM");
    peripheral=*PIVR;
	

	
	switch (peripheral) {
	   case 0x0021: //CMP1
		           CMP1INT_ISR();
				   break;
	   case 0x0022: //CMP2
		           CMP2INT_ISR();
				   break;
	   case 0x0023: // CMP3
		           CMP3INT_ISR();
				   break;
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
	   case 0x0024: // CMP 4
		           CMP4INT_ISR();
				   break;
	   case 0x0025: // CMP5
		           CMP5INT_ISR();
				   break;
	   case 0x0026: // CMP6
		           CMP6INT_ISR();
				   break;
	   case 0x002F: // Timer 3 Period
		           T3PINT_ISR();
				   break;
	   case 0x0030: //Timer 3 Compare
		           T3CINT_ISR();
				   break;
	   case 0x0031: //Timer 3 underflow
		           T3UFINT_ISR();
				   break;
	   case 0x0032: // Timer 3 Overflow
		           T3OFINT_ISR();
				   break;
	} 

	
	
	
}

// *************** INT3 GISR **********************

interrupt void INT3_GISR(void) {// GISR for all INT3 level peripherals
   
    unsigned int peripheral;
	 // reset the core INT3 flag
	IFRbits->bit.INT3FLAG=1;

	asm(" SETC INTM");
    peripheral=*PIVR;
	

	switch (peripheral) {
	   case 0x002B: // Timer 2 period
		           T2PINT_ISR();
				   break;
	   case 0x002C: //Timer 2 Compare
		           T2CINT_ISR();
				   break;
	   case 0x002D:  // Timer 2 underflow
		           T2UFINT_ISR();
				   break;
	   case 0x002E:  // Timer 2 overflow
		           T2OFINT_ISR();
				   break;
	   case 0x0039:  // Timer 4 period
		           T4PINT_ISR();
				   break;
	   case 0x003A: // Timer 4 compare
		           T3CINT_ISR();
				   break;
	   case 0x003B:  // Timer 4 underflow
		           T4UFINT_ISR();
				   break;
	   case 0x003C: //timer 4 overflow
	     	       T4OFINT_ISR();
				   break;
	}

	
	
}

// *************** INT4 GISR **********************

interrupt void INT4_GISR(void) {// GISR for all INT4 level peripherals
	
	unsigned int peripheral;
	// reset INT4 interrupt flag
	IFRbits->bit.INT4FLAG=1;

	asm(" SETC INTM");
    peripheral=*PIVR;
	

	switch (peripheral) {
	   case 0x0033: //Capture 1 
		            CAP1INT_ISR();
					break;
	   case 0x0034: //Capture 2
		            CAP2INT_ISR();
					break;
	   case 0x0035: // Capture 3
		            CAP3INT_ISR();
					break;
	   case 0x0036: //capture 4
		            CAP4INT_ISR();
					break;
	   case 0x0037:  // capture 5
		            CAP5INT_ISR();
					break;
	   case 0x0038:  // capture 6
		            CAP6INT_ISR();
					break;
	}

	
	
}



// ***************INT5 GISR **********************

interrupt void INT5_GISR(void) {// GISR for all INT5 level peripherals
	
	unsigned int peripheral;
	// reset INT 5 flag
	IFRbits->bit.INT5FLAG=1;

	asm(" SETC INTM");
    peripheral=*PIVR;
	

	switch (peripheral) {
	   case 0x0005: //SPI lp
		           SPIINT_LP_ISR();
				   break;
	   case 0x0006:  //SCI RX lp
		           RXINT_LP_ISR();
				   break;
	   case 0x0007:  // SCI TX lp
		           TXINT_LP_ISR();
				   break;
	   case 0x0040:  // CAN mailbox lp
		           CANMBINT_LP_ISR();
				   break;
	   case 0x0041:  // CAN Error lp
		           CANERINT_LP_ISR();
				   break;
	} 
	
	
}


// *************** INT6 GISR **********************

interrupt void INT6_GISR(void) {// GISR for all INT6 level peripherals
	
	unsigned int peripheral;
	// reset INT6 flag
	IFRbits->bit.INT6FLAG=1;

	asm(" SETC INTM");
    peripheral=*PIVR;
	

	switch (peripheral) {

	  case 0x0004:  //ADC lp
		          ADCINT_LP_ISR();
				  break;
	  case 0x0001: // XINT1 lp
	              XINT1_LP_ISR();
				  break;
	  case 0x0011:  // XINT2 lp
		          XINT2_LP_ISR();
				  break;
	}

		
}



// OUF!