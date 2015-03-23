#include "DSP24_Spi.h"
#include "DSP24_Core.h"

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
SPICTLbits->bit.INTENA = 1;      // Enable interrupts

// 3. Baud rate register (SPIBRR) configuration
*SPIBRR = 127;  // minimum bps rate (314,959) for 40Mhz CLKOUT

// 4. Configuring SPI Priority Control Register (SPIPRI)
SPIPRIbits->bit.SPIPRI = 1; // Low priority interrupt requests
SPIPRIbits->bit.SPISOFT = 0;
SPIPRIbits->bit.SPIFREE = 0; // immediate stop on suspend

//5. enabling interrupts
*IFR |= 0x10; // clearing global int5 flag 
*IMR |= 0x10; // unmasking core interrupt 5

//6. enabling the spi
SPICCRbits->bit.SPIRST = 1;


}



void sendCharSPI(unsigned int ch) {

// wait until transmit buffer is available
while (SPISTSbits->bit.TxBUFFULL!=0); 

// place the character
*SPITXBUF = ch;

}