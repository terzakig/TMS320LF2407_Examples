
#include "DSP24_Ev.h"

volatile unsigned int *T1CNT=(void*)0x7401;   /* GP timer 1 counter reg */
volatile unsigned int *T1CMPR=(void*)0x7402;   /* GP timer 1 compare reg */
volatile unsigned int *T1PR=(void*)0x7403;   /* GP timer 1 period */
volatile unsigned int *CMPR1=(void*)0x7417; /* Compare register for Compare unit1 */

volatile unsigned int *T2CNT=(void*)0x7405;
volatile unsigned int *T2PR=(void*)0x7407;
volatile unsigned int *T2CMPR=(void*)0x7406;

volatile unsigned int *CAP1FIFO=(void*)0x7423; // capture channel 1 FIFO top
volatile unsigned int *CAP2FIFO=(void*)0x7424; // capture channel 2 FIFO top
volatile unsigned int *CAP3FIFO=(void*)0x7425; // capture channel 3 FIFO top
volatile unsigned int *CAP1FBOT=(void*)0x7427; // capture channel 1 FIFO bottom
volatile unsigned int *CAP2FBOT=(void*)0x7428; // capture channel 2 FIFO bottom
volatile unsigned int *CAP3FBOT=(void*)0x7429; // capture channel 3 FIFO bottom


// GPTCONA
volatile union GPTCONA_REG *GPTCONAbits=(void*)0x7400;

//T1CON
volatile union T1CON_REG *T1CONbits=(void*)0x7404;

// T2CON
volatile union T2CON_REG *T2CONbits=(void*)0x7408;

// EVAIMRA
volatile union EVAIMRA_REG *EVAIMRAbits=(void*)0x742C;

//EVAIMRB
volatile union EVAIMRB_REG *EVAIMRBbits=(void*)0x742D;

//EVAIMRC
volatile union EVAIMRC_REG *EVAIMRCbits=(void*)0x742E;

// EVAIFRA 
volatile union EVAIFRA_REG *EVAIFRAbits=(void*)0x742F;

//EVAIFRB
volatile union EVAIFRB_REG *EVAIFRBbits=(void*)0x7430;

//EVAIFRC
volatile union EVAIFRC_REG *EVAIFRCbits=(void*)0x7431;

// COMCONA 
volatile union COMCONA_REG *COMCONAbits=(void*)0x7411;

// ACTRA
volatile union ACTRA_REG *ACTRAbits=(void*)0x7413;

// DBTCONA
volatile union DBTCONA_REG *DBTCONAbits=(void*)0x7415;

// CAPFIFOA
volatile union CAPFIFOA_REG *CAPFIFOAbits=(void*)0x7422;

// CAPCONA
volatile union CAPCONA_REG *CAPCONAbits=(void*)0x7420;