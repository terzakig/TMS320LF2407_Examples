#include "DSP24_Core.h"
#include "DSP24_Adc.h"



void initADC_DS(void) {

 
  // 1. Configuring ADCTRL1
  ADCTRL1bits->bit.STESTENA = 0; // self-test mode disabled
  ADCTRL1bits->bit.HILO = 0;     // no effect in normal mode
  ADCTRL1bits->bit.BRGENA = 0;   // no effect in normal mode
  ADCTRL1bits->bit.CALENA = 0;   // calibration mode disabled
  ADCTRL1bits->bit.SEQCASC = 0;  // use dual sequencer mode
  ADCTRL1bits->bit.INTPRI = 0;   // high priority ADC interrupt
  ADCTRL1bits->bit.CONTRUN = 0;  // Start-stop mode
  ADCTRL1bits->bit.CPS = 1;      // Conversion ClOCK = CLKOUT/2
  ADCTRL1bits->bit.ACQPS = 15;    // S/H window time = 32*Tclk=18*Clkout
  ADCTRL1bits->bit.SOFT = 0;
  ADCTRL1bits->bit.FREE = 0;    // immediate stop on suspend
  ADCTRL1bits->bit.RESET = 0;   // no action

  // 2. Configuring ADCTRL2   
  ADCTRL2bits->bit.EVBSOCSEQ2 = 0; // EVB cannot start sequencer2
  ADCTRL2bits->bit.INTFLAGSEQ2 = 1; // clear SEQ2 interrupt flag
  ADCTRL2bits->bit.INTENASEQ2 = 1;  // enable SEQ2 interrupt
  ADCTRL2bits->bit.SOCSEQ2 = 0;    // ignored in cascaded mode
  ADCTRL2bits->bit.RSTSEQ2 = 0;    // no action
  ADCTRL2bits->bit.EXTSOCSEQ1 = 0; // no action
  ADCTRL2bits->bit.EVASOCSEQ1 = 0; // EVA cannot trigger SOC on SEQ1
  ADCTRL2bits->bit.INTFLAGSEQ1 = 1; // clear interrupt SEQ1 flag 
  ADCTRL2bits->bit.INTENASEQ1 = 1;  // enable SEQ1 interrupt
  ADCTRL2bits->bit.SOCSEQ1 = 0;     // no action (clear pending SOC triggers)
  ADCTRL2bits->bit.RSTSEQ1STRTCAL = 1; // no action
  ADCTRL2bits->bit.EVBSOCSEQ = 0;      // EVB does not start cascaded sequencer

  // 3. MAXimum CONversion number (MAXCONv)
  *MAXCONV = 0x0044; // 4 conversions for each sequencer

  // 54. Input Channel Select Sequencing

  // Sequencer 1 channels
  CHSELSEQ1bits->bit.CONV00 = 0; 
  CHSELSEQ1bits->bit.CONV01 = 1;
  CHSELSEQ1bits->bit.CONV02 = 2;
  CHSELSEQ1bits->bit.CONV03 = 3;

  // Sequencer 2 channels
  CHSELSEQ3bits->bit.CONV08 = 8;
  CHSELSEQ3bits->bit.CONV09 = 9;
  CHSELSEQ3bits->bit.CONV10 = 10;
  CHSELSEQ3bits->bit.CONV11 = 11;


  // 6. enable interrupts
    
  // enable int1 core interrupt (for ADC high priority interrupt)
  *IMR |= 0x0001;

  // 7. Start the first sequencer 
   ADCTRL2bits->bit.SOCSEQ1 = 1; // start sequencer 1
   
  
}












