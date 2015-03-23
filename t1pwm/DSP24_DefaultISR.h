#ifndef DSP24_DEFAULT_ISR_H
#define DSP24_DEFAULT_ISR_H

#include "DSP24_Ev.h"
#include "DSP24_Core.h"


// Timer 1 Period Match interrupt
interrupt void T1PINT_ISR(void);
// Timer 1 Compare interrupt
interrupt void T1CINT_ISR(void);
// Timer 1 Underflow interrupt
interrupt void T1UFINT_ISR(void);
// Timer 1 Overflow interrupt
interrupt void T1OFINT_ISR(void);

interrupt void INT1_GISR(void); 

interrupt void INT2_GISR(void); 

interrupt void INT3_GISR(void); 

interrupt void INT4_GISR(void); 

interrupt void INT5_GISR(void); 

interrupt void INT6_GISR(void);


#endif
  

