#include "DSP24_Ev.h"
#include "DSP24_Core.h"

void initTimer1(void) {
     
	 GPTCONAbits->bit.T1PIN=0x2; // T1CMP Compare output active high
	 GPTCONAbits->bit.T2PIN=00;  // T2CMP Comp output active low (not used)
	 GPTCONAbits->bit.TCOMPOE=1;   // Enable all GP Timer Compare outputs
	 GPTCONAbits->bit.T1TOADC=00; // Do not start ADC with Timer1
	 GPTCONAbits->bit.T2TOADC=00; // do not start ADC with Timer2

     
     *T1CNT=0;
	 *T1PR=30000;
	 *T1CMPR=15000;

	 T1CONbits->bit.rsvd1=0; // reserved 
	 T1CONbits->bit.TCMPREN=1; // Enable Timer Compare
	 T1CONbits->bit.TCLD=00;   // reload compare reg on underflow
	 T1CONbits->bit.TMODE=01; // Continuous Up/Down mode
	 T1CONbits->bit.TPS=000;  // Input Clock PreScale /x1
	 T1CONbits->bit.rsvd2=0;
	 T1CONbits->bit.rsvd3=0;
	 T1CONbits->bit.TCLKS=00; // Internal Clock source select
	 T1CONbits->bit.SOFT=0;
	 T1CONbits->bit.FREE=0; // immediate stop on emulation suspend
	 
	 EVAIFRAbits->bit.T1PINT=1; // clear Timer1 Period Match interrupt flag
	 EVAIFRAbits->bit.T1CINT=1; // clear Timer1 Compare interrupt flag
	 EVAIFRAbits->bit.T1UFINT=1;// clear Timer1 UnderFlow interrupt flag
	 EVAIFRAbits->bit.T1OFINT=1;// clear Timer1 OverFlow interrupt flag


	 EVAIMRAbits->bit.T1PINT=1; // enable Timer1 Period Match interrupt
	 EVAIMRAbits->bit.T1CINT=1; // enable Timer1 Compare interrupt
	 EVAIMRAbits->bit.T1UFINT=1;// enable Timer1 UnderFlow interrupt
	 EVAIMRAbits->bit.T1OFINT=1;// enable Timer1 OverFlow interrupt
     
     *IMR|=0x0002; //enable core level interrupt 2

	 T1CONbits->bit.TENABLE=1; // Enable the timer
	
	 
}