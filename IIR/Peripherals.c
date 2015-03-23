#include "Peripherals.h"

void initADC(void) {

  // 1. Configuring ADCTRL1
  ADCTRL1bits->bit.STESTENA = 0; // self-test mode disabled
  ADCTRL1bits->bit.HILO = 0;     // no effect in normal mode
  ADCTRL1bits->bit.BRGENA = 0;   // no effect in normal mode
  ADCTRL1bits->bit.CALENA = 0;   // calibration mode disabled
  ADCTRL1bits->bit.SEQCASC = 1;  // cascaded sequencer mode
  ADCTRL1bits->bit.INTPRI = 1;   // low priority ADC interrupt
  ADCTRL1bits->bit.CONTRUN = 0;  // start-stop mode
  ADCTRL1bits->bit.CPS = 1;      // Conversion ClOCK = CLKOUT/2
  ADCTRL1bits->bit.ACQPS = 15;   // Acquisition window = 32*Tclk=32*Clkout 
  								// (16 x sampling time = 34.4 usec conversion time)
  ADCTRL1bits->bit.SOFT = 0;
  ADCTRL1bits->bit.FREE = 0;    // immediate stop on suspend
  ADCTRL1bits->bit.RESET = 0;   // no action for now

  // 2. Configuring ADCTRL2   
  ADCTRL2bits->bit.EVBSOCSEQ2 = 0; // EVB does not start sequencer2
  ADCTRL2bits->bit.INTFLAGSEQ2 = 1; // clear SEQ2 interrupt flag
  ADCTRL2bits->bit.INTENASEQ2 = 0;  // disable SEQ2 interrupt
  ADCTRL2bits->bit.SOCSEQ2 = 0;    // no action
  ADCTRL2bits->bit.RSTSEQ2 = 0;    // no action
  ADCTRL2bits->bit.EXTSOCSEQ1 = 0; // no action
  ADCTRL2bits->bit.EVASOCSEQ1 = 0; // EVA cannot trigger SOC on SEQ1
  ADCTRL2bits->bit.INTFLAGSEQ1 = 1; // clear interrupt SEQ1 flag 
  ADCTRL2bits->bit.INTENASEQ1 = 1;  // enable SEQ1 interrupt (cascaded)
  ADCTRL2bits->bit.SOCSEQ1 = 0;     // no action (clear pending SOC triggers)
  ADCTRL2bits->bit.RSTSEQ1STRTCAL = 0; // no action
  ADCTRL2bits->bit.EVBSOCSEQ = 0;      // EVB cannot start cascaded sequencer

  // 3. MAXimum CONversion number (MAXCONv)
  *MAXCONV = 15; // 16 conversions by the cascaded sequencer  

  // 4. Input Channel Select Sequencing
  CHSELSEQ1bits->all = 0x1111; // channel #1 sampling
  CHSELSEQ2bits->all = 0x1111; // channel #1 sampling
  CHSELSEQ3bits->all = 0x1111; // channel #1 sampling
  CHSELSEQ4bits->all = 0x1111; // channel #1 sampling
  // 16 samples from channel #1 (oversampling)

  // 5. enable core INT6 interrupt 
  *IMR |= 0x0020;
   
   // Start Cascaded Sequencer
   ADCTRL2bits->bit.SOCSEQ1 = 1;
}

void initTimer1(void) {
     
	 GPTCONAbits->bit.T1PIN=0x2; // T1CMP Compare output active high
	 GPTCONAbits->bit.T2PIN=00;  // T2CMP Comp output active low (not used)
	 GPTCONAbits->bit.TCOMPOE=1;   // Enable all GP Timer Compare outputs
	 GPTCONAbits->bit.T1TOADC=00; // Do not start ADC with Timer1
	 GPTCONAbits->bit.T2TOADC=00; // do not start ADC with Timer2
     
	 
	 // Timer 1 Initialization
     *T1CNT = 0;
	 *T1PR = 48000;   // 1.2 ms timer period
	 *T1CMPR = 2000; // 2.3 ms pulse length  
	 
	 T1CONbits->all = 0;

	 T1CONbits->bit.TCMPREN = 1; // Enable Timer Compare
	 T1CONbits->bit.TCLD = 00;   // reload compare reg on underflow
	 T1CONbits->bit.TMODE = 01; // Continuous Up/Down mode
	 T1CONbits->bit.TPS = 0;  // Input Clock PreScale /x1
	 
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



void initSPI(void) {

// 1. Configuring SPI Configuration Control register (SPICCR)
SPICCRbits->bit.SPIRST = 0; // Reset SPI flags. Output inactive

SPICCRbits->bit.CHARLEN = 15; // 16-bit character length
SPICCRbits->bit.CLKPOL = 0;  // data is sent on rising edge 
							

// 2. Configuring Operation Control Register (SPICTL)
SPICTLbits->bit.OVRNINTENA = 0; // disable receiver overrun
SPICTLbits->bit.CLKPHSEL = 1;   // Normal SPI Clock Phase
SPICTLbits->bit.MST_SLV = 1;    // Device is Master
SPICTLbits->bit.TALK = 1;       // Enable transmission
SPICTLbits->bit.INTENA = 0;      // Disable interrupts

// 3. Baud rate register (SPIBRR) configuration
*SPIBRR = 0;  // maximum bps rate (CLKOUT/4=10,000,000) for 40Mhz CLKOUT

// 4. Configuring SPI Priority Control Register (SPIPRI)
SPIPRIbits->bit.SPIPRI = 1; // Low priority interrupt requests
SPIPRIbits->bit.SPISOFT = 0;
SPIPRIbits->bit.SPIFREE = 0; // immediate stop on suspend


//5. enabling the spi
SPICCRbits->bit.SPIRST = 1;

}


void sendWordSPI(unsigned int wrd) {

// wait until transmit buffer is available
while (SPISTSbits->bit.TxBUFFULL!=0); 

// place the 16-bit word
*SPITXBUF = wrd;

}