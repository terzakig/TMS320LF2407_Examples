//*************************************************************
//*                                                           *
//* Common function for System and Peripheral Initialiazation *
//*															  *
//*                      TMS320LF2407A						  *
//*															  *
//*					George Terzakis 2009	                  *
//*															  *
//*************************************************************

#include "DSP24_SysFunc.h"
#include "f2407_c.h"
#include "DSP24_Core.h"
#include "DSP24_PieSys.h"
#include "DSP24_Gpio.h"
#include "DSP24_Ev.h"
#include "DSP24_Adc.h"


// run initSystem() to initialize device clocks, kick the dog, 
// initialize IO pins

void initSystem(int T1pwm, int T2pwm, int T3pwm, int T4pwm, 
				int CANfunc, int SPIfunc, int SCIfunc, 
				int CAP1func, int CAP2func, int CAP3func,
				int CAP4func, int CAP5func, int CAP6func,
				int pwm1, int pwm2) {
    unsigned int test;

	/*** Configure the System Control and Status registers ***/
    *SCSR1 = 0x00FD;
/*
 bit 15        0:      reserved
 bit 14        0:      CLKOUT = CPUCLK
 bit 13-12     00:     IDLE1 selected for low-power mode
 bit 11-9      000:    PLL x4 mode
 bit 8         0:      reserved
 bit 7         1:      1 = enable ADC module clock
 bit 6         1:      1 = enable SCI module clock
 bit 5         1:      1 = enable SPI module clock
 bit 4         1:      1 = enable CAN module clock
 bit 3         1:      1 = enable EVB module clock
 bit 2         1:      1 = enable EVA module clock
 bit 1         0:      reserved
 bit 0         1:      clear the ILLADR bit
*/

    *SCSR2 = (*SCSR2 | 0x000B) & 0x000F;
/*
 bit 15-6      0's:    reserved
 bit 5         0:      do NOT clear the WD OVERRIDE bit
 bit 4         0:      XMIF_HI-Z, 0=normal mode, 1=Hi-Z'd
 bit 3         1:      disable the boot ROM, enable the FLASH
 bit 2     no change   MP/MC* bit reflects state of MP/MC* pin
 bit 1-0      11:      11 = SARAM mapped to prog and data
*/


/*** Disable the watchdog timer ***/
    *WDCR  = 0x00E8;
/*
 bits 15-8     0's:     reserved
 bit 7         1:       clear WD flag
 bit 6         1:       disable the dog
 bit 5-3       101:     must be written as 101
 bit 2-0       000:     WDCLK divider = 1
*/


	/*** Setup external memory interface for LF2407 EVM ***/
    // values were copied verbatim from a T.I. example
	WSGR = 0x0040;
	/*
	bit 15-11     0's:    reserved
	bit 10-9      00:     bus visibility off
	bit 8-6       001:    1 wait-state for I/O space
	bit 5-3       000:    0 wait-state for data space
	bit 2-0       000:    0 wait state for program space
	*/

// ****** Now seting up functions of I/O PORTA,B,C pins**********
// MCRA
	IOMUXCTRLAbits->bit.SCITXD_GPIOA0=(SCIfunc==useSPI) ? 1 : 0;
	IOMUXCTRLAbits->bit.SCIRXD_GPIOA1=(SCIfunc==useSPI) ? 1 : 0;
	IOMUXCTRLAbits->bit.XINT1_GPIOA2=0; // not using XINTs at all
	IOMUXCTRLAbits->bit.CAP1QEP1_GPIOA3=(CAP1func==useCAP) ? 1 : 0;
	IOMUXCTRLAbits->bit.CAP2QEP2_GPIOA4=(CAP2func==useCAP) ? 1 : 0;
	IOMUXCTRLAbits->bit.CAP3_GPIOA5=(CAP3func==useCAP) ? 1 : 0;
	IOMUXCTRLAbits->bit.PWM1_GPIOA6=(pwm1<=1&&pwm2>=1) ? 1 : 0;
	IOMUXCTRLAbits->bit.PWM2_GPIOA7=(pwm1<=2&&pwm2>=2) ? 1 : 0;
	IOMUXCTRLAbits->bit.PWM3_GPIOB0=(pwm1<=3&&pwm2>=3) ? 1 : 0;
	IOMUXCTRLAbits->bit.PWM4_GPIOB1=(pwm1<=4&&pwm2>=4) ? 1 : 0;
	IOMUXCTRLAbits->bit.PWM5_GPIOB2=(pwm1<=5&&pwm2>=5) ? 1 : 0;
	IOMUXCTRLAbits->bit.PWM6_GPIOB3=(pwm1<=6&&pwm2>=6) ? 1 : 0;
	IOMUXCTRLAbits->bit.T1PWMT1CMP_GPIOB4=(T1pwm==usePWM) ? 1 : 0;
	IOMUXCTRLAbits->bit.T1PWMT2CMP_GPIOAB5=(T1pwm==usePWM) ? 1 : 0;
	IOMUXCTRLAbits->bit.TDIRA_GPIOAB6=0; // standard IO
	IOMUXCTRLAbits->bit.TCLKINA_GPIOAB7=0; // std IO
    test=*MCRA;
    // IO Multplexing register A done...
	
	// IO multiplexing register B
	IOMUXCTRLBbits->bit.WR_GPIOC0=0; // std IO
	IOMUXCTRLBbits->bit.BIO_GPIOC1=0; // std IO
	IOMUXCTRLBbits->bit.SPISIMO_GPIOC2=(SPIfunc==useSPI) ? 1 : 0;
	IOMUXCTRLBbits->bit.SPISOMI_GPIOC3=(SPIfunc==useSPI) ? 1 : 0;
	IOMUXCTRLBbits->bit.SPICLK_GPIOC4=(SPIfunc==useSPI) ? 1 : 0;
	IOMUXCTRLBbits->bit.SPISTE_GPIOC5=(SPIfunc==useSPI) ? 1 : 0;
	IOMUXCTRLBbits->bit.CANTX_GPIOC6=(CANfunc==useCAN) ? 1 : 0;
	IOMUXCTRLBbits->bit.CANRX_GPIOC7=(CANfunc==useCAN) ? 1 : 0;
	IOMUXCTRLBbits->bit.XINTADCSOC_GPIOD0=0; // std io always
	IOMUXCTRLBbits->bit.EMU0_rsvd=1; // always use 1
	IOMUXCTRLBbits->bit.EMU1_rsvd=1; // always use 1
	IOMUXCTRLBbits->bit.TCK_rsvd=1; // always 1
	IOMUXCTRLBbits->bit.TDI_rsvd=1; // always 1
	IOMUXCTRLBbits->bit.TDO_rsvd=1; // always 1
	IOMUXCTRLBbits->bit.TMS_rsvd=1; // always 1
	IOMUXCTRLBbits->bit.TMS2_rsvd=1; // always 1
    test=*MCRB;
	// IO Multiplexing Control register B done

	// IO Multiplexing Control register C 
	IOMUXCTRLCbits->bit.CLKOUT_GPIOE0=0; // std always GPIO
	IOMUXCTRLCbits->bit.PWM7_GPIOE1=(pwm1<=7&&pwm2>=7) ? 1 : 0;
	IOMUXCTRLCbits->bit.PWM8_GPIOE2=(pwm1<=8&&pwm2>=8) ? 1 : 0;
	IOMUXCTRLCbits->bit.PWM9_GPIOE3=(pwm1<=9&&pwm2>=9) ? 1 : 0;
	IOMUXCTRLCbits->bit.PWM10_GPIOE4=(pwm1<=10&&pwm2>=10) ? 1 : 0;
	IOMUXCTRLCbits->bit.PWM11_GPIOE5=(pwm1<=11&&pwm2>=11) ? 1 : 0;
	IOMUXCTRLCbits->bit.PWM12_GPIOE6=(pwm1<=12&&pwm2>=12) ? 1 : 0;
	IOMUXCTRLCbits->bit.CAP4QEP3_GPIOE7=(CAP4func==useCAP)? 1 : 0;
	IOMUXCTRLCbits->bit.CAP5QEP4_GPIOF0=(CAP5func==useCAP)? 1 : 0;
	IOMUXCTRLCbits->bit.CAP6_GPIOF1=(CAP6func==useCAP)? 1 : 0;
	IOMUXCTRLCbits->bit.T3PWMT3CMP_GPIOF2=(T3pwm==usePWM) ? 1 : 0;
	IOMUXCTRLCbits->bit.T4PWMT4CMP_GPIOF3=(T4pwm==usePWM) ? 1 : 0;
    IOMUXCTRLCbits->bit.TDIRB_GPIOF4=0; // always std GPIO
	IOMUXCTRLCbits->bit.TCLKINB_GPIOF5=0; // always std GPIO
	test=*MCRC;
	// IO Mux Control C done
//**************** IO pin configuration DONE ****************

	
	
	// Masking Interrupt levels 1-6
	*IMR=0x0000;
	// INT1-6 unmasked

	//Clearing any pending interrupt flags
	IFRbits->bit.INT1FLAG=1;
	IFRbits->bit.INT2FLAG=1;
	IFRbits->bit.INT3FLAG=1;
	IFRbits->bit.INT4FLAG=1;
	IFRbits->bit.INT5FLAG=1;
	IFRbits->bit.INT6FLAG=1;
	IFRbits->bit.rsvd1=0;
    test=*IFR;
}


// initPWMEVA() initializes EVA to produce PWM
// on all PWM1-6 pins. Each pair of pins carries 
// the duty1, duty2, duty3 pulses
// no Timer starts ADC
void initPWMEVA(int prd, double duty1, double duty2, double duty3)
{
    unsigned int test;
    // First Disabling Timer1 and Timer2
	// in order to setup the PWM
	*T1CON = 0x0000;                    /* disable timer 1 */
    *T2CON = 0x0000;                    /* disable timer 2 */

    *GPTCONA = 0x0000;                  /* configure GPTCONA */
/*     
 bit 15        0:      reserved
 bit 14        0:      T2STAT, read-only
 bit 13        0:      T1STAT, read-only
 bit 12-11     00:     reserved
 bit 10-9      00:     T2TOADC, 00 = no timer2 event starts ADC
 bit 8-7       00:     T1TOADC, 00 = no timer1 event starts ADC
 bit 6         0:      TCOMPOE, 0 = Hi-z all timer compare outputs
 bit 5-4       00:     reserved
 bit 3-2       00:     T2PIN, 00 = forced low
 bit 1-0       00:     T1PIN, 00 = forced low
*/


/* Timer 1: configure to clock the PWM on PWM1 pin */

    *T1CNT = 0x0000;            /* clear timer counter */
    *T1PR = 60*prd;               /*1 increment/decrement is 1/60 usec set timer period */
    *DBTCONA = 0x0000;          /* deadband units off */
    *CMPR1 = (int)(60*prd*duty1);      /* set PWM1 duty cycle as a percentage of period*/
    *CMPR2 = (int)(60*prd*duty2);
	*CMPR3 = (int)(60*prd*duty3);
    
    // Now setting up ACTRA
     
	 ACTRAbits->bit.CMP1ACT1=2; // PWM1 actibe high
	 ACTRAbits->bit.CMP2ACT1=1; // PWM2 active low
	 ACTRAbits->bit.CMP3ACT1=2; // PWM3 active high
	 ACTRAbits->bit.CMP4ACT1=1; // PWM4 active low
	 ACTRAbits->bit.CMP5ACT1=2; // PWM5 active high
	 ACTRAbits->bit.CMP6ACT1=1; // PWM6 active low
	 ACTRAbits->bit.D0=0;
	 ACTRAbits->bit.D1=0;
	 ACTRAbits->bit.D2=0; // Basic space vector D2D1D0 is "don't care"
	 ACTRAbits->bit.SVRDIR=0; // S.V. dir is again "don't care"
	 test=*ACTRA;
	 // *ACTRA = 0x0666;           
     
     // Now setting up COMpare CONfiguration register A
     
     COMCONAbits->bit.rsvd1=0; 
	 COMCONAbits->bit.PDPINTASTAT=0; // bits 0-8 are 0
     COMCONAbits->bit.FCOMPOE=1; // enable PWM pins
     COMCONAbits->bit.CLD=00; // Reload Compare regs on T1 Underflow
     COMCONAbits->bit.ACTRLD=00; // Reload Actra on T1 Underflow
     COMCONAbits->bit.SVENABLE=0; // Disable Spacve vector
     COMCONAbits->bit.CENABLE=1; // Enable Comparison                 
	 test=*COMCONA;
	 //  *COMCONA = 0x8200;
    
	 // Now configuring Timer1 - T1CON
	 T1CONbits->bit.rsvd1=0; // reserved (its the priod register select bit
	 T1CONbits->bit.TCMPREN=0; // Disable Timer Compare
	 T1CONbits->bit.TCLD=00;   // reload compare reg on underflow
	 T1CONbits->bit.TMODE=01; // Continuous Up/Down mode
	 T1CONbits->bit.TPS=000;  // Input Clock PreScale /x1
	 T1CONbits->bit.rsvd2=0;
	 T1CONbits->bit.rsvd3=0;
	 T1CONbits->bit.TCLKS=00; // Internal Clock source select
	 T1CONbits->bit.soft=0;
	 T1CONbits->bit.free=0; // immediate stop on emulation suspend
	 T1CONbits->bit.TENABLE=1; // Enable the timer
	 test=*T1CON;
	 //     *T1CON = 0x0840;                   



    *IMR |= 0x0002;                      
    /* enable core interrupts (INT2)*/

    /*** Setup the event manager interrupts ***/
    
    EVAIMRAbits->bit.T1UFINT=1;
                                        
    *EVAIMRB = 0x0000;                  /* enable desired EVA group B interrupts */
    *EVAIMRC = 0x0000;                  /* enable desired EVA group C interrupts */
    
}    


// specify sample period sampleprd, in usecs

void initADC(int sampleprd)
{
	unsigned int test;

	*T4CNT=0x0000; // clearing Timer counter
	
	// Now initializing Timer4
    T4CONbits->bit.T3PERSEL=0; // Use own period register
	T4CONbits->bit.TCMPREN=0;   // Timer Compare operation disabled
    T4CONbits->bit.TCLD=11;     // Doesnt matter
    T4CONbits->bit.TCLKS=00;   // Select internal clock source
    T4CONbits->bit.T4SWT3=0;   // Use own Timer Enable bit to start
    T4CONbits->bit.TPS=7;     // Input Clock PreSCaler /x128
    T4CONbits->bit.TMODE=2;   // Continus Up Mode
	T4CONbits->bit.soft=0;
	T4CONbits->bit.free=0;    // immediate stop on emulation suspend
	T4CONbits->bit.TENABLE=0;  // Keep the Timer disabled for now...
    test=*T4CON; 
    //*T4CON=0x170c;  0001 / 0111 / 0000 / 1100
    
	// now storing period in T4PR
	*T4PR=600; // presumably 1 UF interrupt every 1ms 
	// Configuring General Purpose Timer  CONfiguration register B
	// must specify Start of Conversion with T4
    //*GPTCONB=0x400;
	GPTCONBbits->bit.T3PIN=00; // Forced T3pin to low
	GPTCONBbits->bit.T4PIN=00; // Forced T4pin low
	GPTCONBbits->bit.rsvd1=00; // reserved
	GPTCONBbits->bit.TCOMPOE=00; // Disable Timer4 compare outputs
	GPTCONBbits->bit.T3TOADC=00; // T3 does does not affect ADC
	GPTCONBbits->bit.T4TOADC=01; // 01 start ADC on underflow
	test=*GPTCONB;
	// that's it. rest of bits are either reserved or read-only
	*EVBIFRB=0xffff; // Clearing all Interrupt flags of EVent manager B
	// now configuring the ADC
	// ADC Configuration register 1
	
	ADCTRL1bits->bit.STESTENA=0; // self test function disabled
	ADCTRL1bits->bit.HILO=0;     // has no effect here (only in self test)
	ADCTRL1bits->bit.BRGENA=0;   // has meaning only in calibration
	ADCTRL1bits->bit.CALENA=0;   // has meaning in calibration
	ADCTRL1bits->bit.SEQCASC=1;  // Cascaded mode. best stick at that :)
	ADCTRL1bits->bit.INTPRI=0;   // High priority interrupt
	ADCTRL1bits->bit.CONTRUN=1;  // ADC continues run (reset sequencer after EOS)
	ADCTRL1bits->bit.CPS=1;      // /x2 internal clock prescaling
	ADCTRL1bits->bit.ACQPS=15; // Acquisition prescaling. Parameter sampleprd
	ADCTRL1bits->bit.SOFT=0;
	ADCTRL1bits->bit.FREE=0;        // immediate stop on suspend
	ADCTRL1bits->bit.RESET=0;       // 0 has no effect
	test=*ADCTRL1;
	//*ADCTRL1=0x10;
	
	// Now setting ADC Control register 2
	ADCTRL2bits->bit.RSTSEQ2=0;    // No action (if write 1 it reset SEQ2)
	ADCTRL2bits->bit.EXTSOCSEQ1=0;  // SEQ1 will not be started externally
	ADCTRL2bits->bit.EVASOCSEQ1=0;  // EVA will not trigger SEQ1 SOC
	ADCTRL2bits->bit.EVBSOCSEQ2=0; // SEQ2 SOC won't be triggered by EVB
	ADCTRL2bits->bit.INTFLAGSEQ2=1; // Writing 1 to clear the ADC interrupt flag
	ADCTRL2bits->bit.INTENASEQ2=01; // Enabling SEQuencer2 INTerrupt(immediate request on flag=1)
	ADCTRL2bits->bit.INTENASEQ1=01; // 01 SEQ1 interrupt must be enabled
	ADCTRL2bits->bit.INTFLAGSEQ1=1;  // Clear SEQ1 interrupt flag
	ADCTRL2bits->bit.RSTSEQ1STRTCAL=0; // No action
	ADCTRL2bits->bit.EVBSOCSEQ=1;     // start SOC for cascaded sequencer
	test=*ADCTRL2;
	//*ADCTRL2=0x8404; 1000 / 0100 / 0000 / 0100
	*MAX_CONV=0x0F; // 16 conversions
	// Now selecting channel ch0 only for 16 conversions
    
	*CHSELSEQ1=0x1111;
	*CHSELSEQ2=0x1111;
	*CHSELSEQ3=0x1111;
	*CHSELSEQ4=0x1111;

	// enabling core interrupt 1 (high priority ADC)
	*IMR|=0x0001;
	// starting timer 4 in order to trigger conversion
	T4CONbits->bit.TENABLE=1; // start the timer

	IODIRDATCbits->bit.C2DIR=1; // making C2 an ouput to toggle
	                            // at each ADC interrupt
	IODIRDATCbits->bit.IOPC2=0; // Make it LOW 
}
