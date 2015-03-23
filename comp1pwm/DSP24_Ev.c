
#include "DSP24_Ev.h"

volatile unsigned int *T1CNT=(void*)0x7401;   /* GP timer 1 counter reg */
volatile unsigned int *T1CMPR=(void*)0x7402;   /* GP timer 1 compare reg */
volatile unsigned int *T1PR=(void*)0x7403;   /* GP timer 1 period */
volatile unsigned int *CMPR1=(void*)0x7417; /* Compare register for Compare unit1 */

// GPTCONA
volatile union GPTCONA_REG *GPTCONAbits=(void*)0x7400;

//T1CON
volatile union T1CON_REG *T1CONbits=(void*)0x7404;

// EVAIMRA
volatile union EVAIMRA_REG *EVAIMRAbits=(void*)0x742C;

// EVAIFRA 
volatile union EVAIFRA_REG *EVAIFRAbits=(void*)0x742F;

// COMCONA 
volatile union COMCONA_REG *COMCONAbits=(void*)0x7411;

// ACTRA
volatile union ACTRA_REG *ACTRAbits=(void*)0x7413;

// DBTCONA
volatile union DBTCONA_REG *DBTCONAbits=(void*)0x7415;

