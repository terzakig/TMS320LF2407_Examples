#ifndef DSP24_DEFAULT_ISR_H
#define DSP24_DEFAULT_ISR_H

#include "DSP24_Ev.h"
#include "DSP24_Core.h"
#include "DSP24_Adc.h"
#include "DSP24_Gpio.h" 

#include "Globals.h"
#include "Peripherals.h"


// Timer 1 Period Match interrupt
interrupt void T1PINT_ISR(void);
// Timer 1 Compare interrupt
interrupt void T1CINT_ISR(void);
// Timer 1 Underflow interrupt
interrupt void T1UFINT_ISR(void);
// Timer 1 Overflow interrupt
interrupt void T1OFINT_ISR(void);

// Compare 1 Interrupt
interrupt void CMP1INT_ISR(void);

// Compare 2 Interrupt
interrupt void CMP2INT_ISR(void);

// Capture 1 Interrupt
interrupt void CAP1INT_ISR(void);

// Capture 2 Interrupt
interrupt void CAP2INT_ISR(void);

// ADC high priority interrupt
interrupt void ADCINTHP_ISR();

// ADC low priority interrupt
interrupt void ADCINTLP_ISR();

// SCI low priority Receive interrupt
interrupt void RXINTLP_ISR(void);

// SCI low priority Transmit
interrupt void TXINTLP_ISR(void);

// SPI low priority interrupt
interrupt void SPIINTLP_ISR(void);

// CAN mailbox high priority interrupt
interrupt void CANMBINTHP_ISR(void);

// CAN error high priority interrupt
interrupt void CANERINTHP_ISR(void);



interrupt void INT1_GISR(void); 

interrupt void INT2_GISR(void); 

interrupt void INT3_GISR(void); 

interrupt void INT4_GISR(void); 

interrupt void INT5_GISR(void); 

interrupt void INT6_GISR(void);


#endif
  

