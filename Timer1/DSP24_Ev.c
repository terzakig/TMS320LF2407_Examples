
#include "DSP24_Ev.h"

volatile unsigned int *T1CNT=(void*)0x7401;   /* GP timer 1 counter reg */
volatile unsigned int *T1CMPR=(void*)0x7402;   /* GP timer 1 compare reg */
volatile unsigned int *T1PR=(void*)0x7403;   /* GP timer 1 period reg  */



//T1CON
volatile union T1CON_REG *T1CONbits=(void*)0x7404;

// EVAIMRA
volatile union EVAIMRA_REG *EVAIMRAbits=(void*)0x742C;

// EVAIFRA 
volatile union EVAIFRA_REG *EVAIFRAbits=(void*)0x742F;
