#include "DSP24_Core.h"
#include "DSP24_Ev.h"
#include "DSP24_Adc.h"


void initADC_CS(void) {

  // 1. Configuring ADCTRL1
  ADCTRL1bits->bit.STESTENA = 0; // self-test mode disabled
  ADCTRL1bits->bit.HILO = 0;     // no effect in normal mode
  ADCTRL1bits->bit.BRGENA = 0;   // no effect in normal mode
  ADCTRL1bits->bit.CALENA = 0;   // calibration mode disabled
  ADCTRL1bits->bit.SEQCASC = 1;  // use cascaded sequencer mode
  ADCTRL1bits->bit.INTPRI = 0;   // high priority ADC interrupt
  ADCTRL1bits->bit.CONTRUN = 1;  // Continuous conversion mode
  ADCTRL1bits->bit.CPS = 0;      // Conversion ClOCK = CLKOUT/1
  ADCTRL1bits->bit.ACQPS = 9;    // Acquisition time = 18*Tclk=18*Clkout
  ADCTRL1bits->bit.SOFT = 0;
  ADCTRL1bits->bit.FREE = 0;    // immediate stop on suspend
  ADCTRL1bits->bit.RESET = 0;   // no action for now

  // 2. Configuring ADCTRL2   
  ADCTRL2bits->bit.EVBSOCSEQ2 = 0; // EVB cannot start sequencer2
  ADCTRL2bits->bit.INTFLAGSEQ2 = 1; // clear SEQ2 interrupt flag
  ADCTRL2bits->bit.INTENASEQ2 = 0;  // disable SEQ2 interrupt
  ADCTRL2bits->bit.SOCSEQ2 = 0;    // ignored in cascaded mode
  ADCTRL2bits->bit.RSTSEQ2 = 0;    // no action
  ADCTRL2bits->bit.EXTSOCSEQ1 = 0; // no action
  ADCTRL2bits->bit.EVASOCSEQ1 = 0; // EVA cannot trigger SOC on SEQ1
  ADCTRL2bits->bit.INTFLAGSEQ1 = 1; // clear interrupt SEQ1 flag 
  ADCTRL2bits->bit.INTENASEQ1 = 1;  // enable SEQ1 interrupt
  ADCTRL2bits->bit.SOCSEQ1 = 0;     // no action (clear pending SOC triggers)
  ADCTRL2bits->bit.RSTSEQ1STRTCAL = 0; // no action
  ADCTRL2bits->bit.EVBSOCSEQ = 0;      // EVB does not start cascaded sequencer

  // 3. MAXimum CONversion number (MAXCONv)
  *MAXCONV = 0x000F; // 16 conversions

  // 54. Input Channel Select Sequencing
  CHSELSEQ1bits->bit.CONV00 = 0; 
  CHSELSEQ1bits->bit.CONV01 = 1;
  CHSELSEQ1bits->bit.CONV02 = 2;
  CHSELSEQ1bits->bit.CONV03 = 3;

  CHSELSEQ2bits->bit.CONV04 = 4;
  CHSELSEQ2bits->bit.CONV05 = 5;
  CHSELSEQ2bits->bit.CONV06 = 6;
  CHSELSEQ2bits->bit.CONV07 = 7;

  CHSELSEQ3bits->bit.CONV08 = 8;
  CHSELSEQ3bits->bit.CONV09 = 9;
  CHSELSEQ3bits->bit.CONV10 = 10;
  CHSELSEQ3bits->bit.CONV11 = 11;

  CHSELSEQ4bits->bit.CONV12 = 12;
  CHSELSEQ4bits->bit.CONV13 = 13;
  CHSELSEQ4bits->bit.CONV14 = 14;
  CHSELSEQ4bits->bit.CONV15 = 15;
  // all channels sampled once

  // 6. enable interrupts
    
  // enable int1 core interrupt (ADC high priority interrupt)
  *IMR |= 0x0001;

  // 7. Start the ADC (Software trigger)
   ADCTRL2bits->bit.SOCSEQ1 = 1; 
}












