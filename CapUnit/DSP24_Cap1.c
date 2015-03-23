#include "DSP24_Ev.h"
#include "DSP24_Core.h"


void initCap1(void) {
  // 1. Initializing Genera Purpose Timer Register A
  GPTCONAbits->bit.T1PIN=0;// timer1 compare output pin forced low
  GPTCONAbits->bit.T2PIN=0;// timer2 compare output pin forced low
  GPTCONAbits->bit.T1TOADC=00; // timer1 does not start ADC
  GPTCONAbits->bit.T2TOADC=00; // timer2 does not start ADC
  GPTCONAbits->bit.TCOMPOE=00; // disable compare outputs of timer1 timer2
  

  T2CONbits->all=0x0000; // reset the timer
  // 2. Configuring Timer2 Period and initializing counter
  *T2CNT=0; // reseting the Timer2 counter
  *T2PR=60000; // 3 ms period for /x1 prescaling  

  // 3. Configuring Timer2 Control Register
  T2CONbits->bit.T1PERSEL=0; // use own period register
  T2CONbits->bit.TCMPREN=1; // Disable Timer Compare operation
  T2CONbits->bit.TCLD=00;   // reload compare reg on underflow
  T2CONbits->bit.TMODE=01; // Continuous Up/Down mode
  T2CONbits->bit.TPS=000;  // Input Clock PreScale /x1
  T2CONbits->bit.T2SWT1=0;
  T2CONbits->bit.TCLKS=00; // Internal Clock source select
  T2CONbits->bit.SOFT=0;
  T2CONbits->bit.FREE=0; // immediate stop on emulation suspend
   
  
  // 4.Configuring CAPture CONtrol Register A (CAPCONA)
  CAPCONAbits->bit.CAPRES=0; // Clear all capture registers

  // configuring now
  CAPCONAbits->bit.CAP3EDGE=00; // No Detection
  CAPCONAbits->bit.CAP2EDGE=2; // CAP2 Detects falling edge
  CAPCONAbits->bit.CAP1EDGE=01; // CAP1 Detects rising edge
  CAPCONAbits->bit.CAP3TOADC=0; // CAP3 does not start ADC
  CAPCONAbits->bit.CAP12TSEL=0; // Select Timer 2 for CAP1 and 2
  CAPCONAbits->bit.CAP3TSEL=0; // Select Timer 2 for CAP3
  CAPCONAbits->bit.CAP3EN=0; // Disable CAP3
  
  
  // 5. Configuring Interrupts
  EVAIFRCbits->bit.CAP1INT=1; // Clear CAP1 interrupt flag
  EVAIFRCbits->bit.CAP2INT=1; // Clear CAP2 interrupt flag

  EVAIMRCbits->bit.CAP1INT=1; // Enable CAP1 interrupt
  EVAIMRCbits->bit.CAP2INT=1; // Enable CAP2 interrupt

  
  *IMR|=0x8; // Unmasking core INT4 
  
  // 4. starting timer2
  
  T2CONbits->bit.TENABLE=1;
  CAPCONAbits->bit.CAP12EN=01; // Enable CAP1 and CAP2
  
 
 }