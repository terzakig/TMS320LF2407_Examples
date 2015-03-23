#include "DSP24_Sci.h"
#include "DSP24_Core.h"

void initSCI(void) {

 // configuring Communication Control Register
 SCICCRbits->bit.SCICHAR = 7; // 8 bit character
 SCICCRbits->bit.ADDRIDLE_MODE = 0; // Idle mode (no wake bit in frame)
 SCICCRbits->bit.LOOPBKENA = 0; // Loop back disabled
 SCICCRbits->bit.PARITYENA = 0; // Parity Disabled
 SCICCRbits->bit.PARITY = 0; // No effect (0 is Odd)
 SCICCRbits->bit.STOPBITS = 0; // 1 Stop bit
 
 // Configuring Baud rate to 19200 -> BRR = 0x0103
 *SCILBAUD = 0x03;
 *SCIHBAUD = 0x01;

 // Configuring SCI control register 1
 SCICTL1bits->bit.RXENA = 1; // enable receive
 SCICTL1bits->bit.TXENA = 1; // enable transmit
 SCICTL1bits->bit.SLEEP = 0; // Sleep mode disabled
 SCICTL1bits->bit.TXWAKE = 0; // Transmit feature not selected
 SCICTL1bits->bit.RXERRINTENA = 1; // enable error interrupt
 
 // Configuring SCI Control Register 2
 SCICTL2bits->bit.TXINTENA = 0; // disable transmit interrupt
 SCICTL2bits->bit.RXBKINTENA = 1; // Enabled receive interrupt
 
 // Configuring interrupt priority
 SCIPRIbits->bit.SCIRXPRI = 1;
 SCIPRIbits->bit.SCITXPRI = 1;
 SCIPRIbits->bit.FREE =0;
 SCIPRIbits->bit.SOFT = 0; // immediate stop on suspend
 // Reseting registers (configuration not affected)
 SCICTL1bits->bit.SWRESET = 0; // reset
 SCICTL1bits->bit.SWRESET = 1; // release from reset

  
 // Unmasking core interrupt 5
 *IMR |= 0x10;
 
}

void sendChar(char c) {

  while (SCICTL2bits->bit.TXRDY!=1); // wait for transmit ready

  *SCITXBUF = (int)c;
  
}