#include "DSP24_Gpio.h"

#define WDCR         (volatile unsigned int *)0x7029
#define SCSR1        (volatile unsigned int *)0x7018   
#define SCSR2        (volatile unsigned int *)0x7019
#define INTMASK      (volatile unsigned int *)0x0004

#define WSGR portFFFF                                  
ioport unsigned int portFFFF;


void initSystem(void) {

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

    *WDCR  = 0x00E8;
	/*
	bits 15-8     0's:     reserved
	bit 7         1:       clear WD flag
	bit 6         1:       disable the dog
	bit 5-3       101:     must be written as 101
	bit 2-0       000:     WDCLK divider = 1
	*/

	WSGR = 0x0040;
	/*
	bit 15-11     0's:    reserved
	bit 10-9      00:     bus visibility off
	bit 8-6       001:    1 wait-state for I/O space
	bit 5-3       000:    0 wait-state for data space
	bit 2-0       000:    0 wait state for program space
	*/
	*INTMASK = 0;  // masking core interrupts
}

void initIO(void) {
 
  // setting up CAP1 and CAP2 for edge detection operation
  MCRAbits->bit.CAP1QEP1_GPIOA3=1;
  MCRAbits->bit.CAP2QEP2_GPIOA4=1;
  MCRAbits->bit.CAP3_GPIOA5=1;
 }  


