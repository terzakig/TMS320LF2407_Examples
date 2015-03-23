#include "DSP24_Ev.h"
#include "DSP24_Core.h"





void initPwm() {
  
  T1CONbits->all = 0x0000; // clear Timer1 Control register
  
  // 1. Configuring General Purpose Timer CONtrol Register A (GPTCONA)
  GPTCONAbits->bit.T1PIN=0;// timer1 compare output pin forced low
  GPTCONAbits->bit.T2PIN=0;// timer2 compare output pin forced low
  GPTCONAbits->bit.T1TOADC=00; // timer1 does not start ADC
  GPTCONAbits->bit.T2TOADC=00; // timer2 does not start ADC
  GPTCONAbits->bit.TCOMPOE=00; // disable compare outputs of timer1 timer2
  
  *T1CNT=0; // clearing timer1 counter
  *T1PR=30000; // setting timer1 period to 30000 (192 ms bewteen underflow)
   
  // 2. Configuring Timer 1 Control register
  T1CONbits->bit.rsvd1=0; // reserved 
  T1CONbits->bit.TCMPREN=0; // Disable Timer Compare operation
  T1CONbits->bit.TCLD=00;   // reload compare reg on underflow
  T1CONbits->bit.TMODE=01; // Continuous Up/Down mode
  T1CONbits->bit.TPS=03;  // Input Clock PreScale /x128
  T1CONbits->bit.rsvd2=0;
  T1CONbits->bit.rsvd3=0;
  T1CONbits->bit.TCLKS=00; // Internal Clock source select
  T1CONbits->bit.soft=0;
  T1CONbits->bit.free=0; // immediate stop on emulation suspend


  // Now setting up Compare ACtion control Register A(ACTRA)     
  ACTRAbits->bit.CMP1ACT=2; // PWM1 actibe high
  ACTRAbits->bit.CMP2ACT=1; // PWM2 active low
  ACTRAbits->bit.CMP3ACT=00; // PWM3 forced low
  ACTRAbits->bit.CMP4ACT=00; // PWM4 forced low
  ACTRAbits->bit.CMP5ACT=00; // PWM5 forced low
  ACTRAbits->bit.CMP6ACT=00; // PWM6 forced low
  ACTRAbits->bit.D0=0;
  ACTRAbits->bit.D1=0;
  ACTRAbits->bit.D2=0; // Basic space vector D2D1D0 is "don't care"
  ACTRAbits->bit.SVRDIR=0; // S.V. dir is again "don't care"

  *CMPR1=15000; // setting Compare register to half the timer's period */
  
  // Now setting up COMpare CONfiguration register A
     
  COMCONAbits->bit.rsvd1=0; 
  COMCONAbits->bit.FCOMPOE=1; // enable PWM pins
  COMCONAbits->bit.CLD=00; // Reload Compare regs on Timer1 UnderFlow
  COMCONAbits->bit.ACTRLD=00; // Reload Actra on Timer1 UnderFlow
  COMCONAbits->bit.SVENABLE=0; // Disable Spacve vector
  COMCONAbits->bit.CENABLE=1; // Enable Comparison                 

   // setting up the deadband unit
  DBTCONAbits->bit.DBTPS=000; // Deadband timer prescale /x1
  DBTCONAbits->bit.EDBT1=0; // disable DB timer for PWM1 and PWM2 pins
  DBTCONAbits->bit.EDBT2=0; // disable DB timer for PWM3 and PWM4 pins
  DBTCONAbits->bit.EDBT3=0; // disable DB timer for PWM5 and PWM6 pins
  DBTCONAbits->bit.DBT=0000; // DB period set to 0. 
  
  
  // Configuring - Initiating Interrupts
  EVAIFRAbits->bit.T1UFINT=1;// clear Timer1 UnderFlow interrupt flag
   
  EVAIMRAbits->bit.T1UFINT=1;// enable Timer1 UnderFlow interrupt

  EVAIFRAbits->bit.CMP1INT=1;// clear Compare1 Interrupt

  EVAIMRAbits->bit.CMP1INT=1;// enable Compare1 Interrupt

  *IMR|=0x2; // enabling core level INT2

   // Starting Timer1
   T1CONbits->bit.TENABLE = 1;
}	 