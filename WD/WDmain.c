// Using the Watch Dog
//
// George Terzakis 2009
//
// From the book: "Introduction to C programming with the TMS320LF2407 DSP Controller"

#include "DSP24_Ev.h"
#include "DSP24_Core.h"

extern initSystem(void);

void initTimer();



void main() {
 
  initSystem();  
  initTimer();
  
  

  // enable global interrupts
  asm(" CLRC INTM");
  // main loop
  while (1) {	

  }

}


void initTimer(void) {
       
	 GPTCONAbits->bit.T1PIN=0x2; // T1CMP Compare output active high
	 GPTCONAbits->bit.T2PIN=00;  // T2CMP Comp output active low (not used)
	 GPTCONAbits->bit.TCOMPOE=0;   // disable all GP Timer Compare outputs
	 GPTCONAbits->bit.T1TOADC=00; // Do not start ADC with Timer1
	 GPTCONAbits->bit.T2TOADC=00; // do not start ADC with Timer2
     
	 
	 // Timer 1 Initialization
     *T1CNT = 0;
	 *T1PR = 48000;   // 1.2 ms timer period
	 
	 T1CONbits->all = 0;

	 T1CONbits->bit.TCMPREN = 0; // Disable Timer Compare
	 T1CONbits->bit.TCLD = 0;   // reload compare reg on underflow (irrelevant)
	 T1CONbits->bit.TMODE = 2; // Continuous Up/Down mode
	 T1CONbits->bit.TPS = 3;  // Input Clock PreScale /x1
	 
	 T1CONbits->bit.TCLKS = 0; // Internal Clock source select
	 T1CONbits->bit.SOFT = 0;
	 T1CONbits->bit.FREE = 0; // immediate stop on emulation suspend
	 
	 
     // enable Timer 1 Period interrupt
     EVAIFRAbits->bit.T1PINT = 1; // clear T1PINT flag
     EVAIMRAbits->bit.T1PINT = 1; // enable interrupt
     
     // enable core interrupt INT 2 (timer 1)
	 *IMR |= 2;
	 
	 // start the timer
	 T1CONbits->bit.TENABLE = 1; // Enable Timer 1

}