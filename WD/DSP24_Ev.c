
#include "DSP24_Ev.h"

volatile unsigned int *T1CNT=(void*)0x7401;   /* GP timer 1 counter reg */
volatile unsigned int *T1CMPR=(void*)0x7402;   /* GP timer 1 compare reg */
volatile unsigned int *T1PR=(void*)0x7403;   /* GP timer 1 period */


volatile unsigned int *T2CNT=(void*)0x7405;
volatile unsigned int *T2CMPR=(void*)0x7406;
volatile unsigned int *T2PR=(void*)0x7407;

volatile unsigned int *CMPR1=(void*)0x7417; /* Compare register for Compare unit1 */
volatile unsigned int *CMPR2=(void*)0x7418; /* Compare register for Compare unit2 */
volatile unsigned int *CMPR3=(void*)0x7419; /* Compare register for Compare unit3 */


volatile unsigned int *T3CNT=(void*)0x7501;   /* GP timer 1 counter reg */
volatile unsigned int *T3CMPR=(void*)0x7502;   /* GP timer 1 compare reg */
volatile unsigned int *T3PR=(void*)0x7503;   /* GP timer 1 period */

volatile unsigned int *T4CNT=(void*)0x7505;
volatile unsigned int *T4CMPR=(void*)0x7506;
volatile unsigned int *T4PR=(void*)0x7507;


volatile unsigned int *CMPR4=(void*)0x7517; /* Compare register for Compare unit4 */
volatile unsigned int *CMPR5=(void*)0x7518; /* Compare register for Compare unit5 */
volatile unsigned int *CMPR6=(void*)0x7517; /* Compare register for Compare unit6 */


volatile unsigned int *CAP1FIFO=(void*)0x7423; // capture channel 1 FIFO top
volatile unsigned int *CAP2FIFO=(void*)0x7424; // capture channel 2 FIFO top
volatile unsigned int *CAP3FIFO=(void*)0x7425; // capture channel 3 FIFO top
volatile unsigned int *CAP1FBOT=(void*)0x7427; // capture channel 1 FIFO bottom
volatile unsigned int *CAP2FBOT=(void*)0x7428; // capture channel 2 FIFO bottom
volatile unsigned int *CAP3FBOT=(void*)0x7429; // capture channel 3 FIFO bottom

volatile unsigned int *CAP4FIFO=(void*)0x7523; // capture channel 4 FIFO top
volatile unsigned int *CAP5FIFO=(void*)0x7524; // capture channel 5 FIFO top
volatile unsigned int *CAP6FIFO=(void*)0x7525; // capture channel 6 FIFO top
volatile unsigned int *CAP4FBOT=(void*)0x7527; // capture channel 4 FIFO bottom
volatile unsigned int *CAP5FBOT=(void*)0x7528; // capture channel 5 FIFO bottom
volatile unsigned int *CAP6FBOT=(void*)0x7529; // capture channel 6 FIFO bottom


// GPTCONA
volatile union GPTCONA_REG *GPTCONAbits=(void*)0x7400;

// GPTCONB
volatile union GPTCONB_REG *GPTCONBbits=(void*)0x7500;

//T1CON
volatile union T1CON_REG *T1CONbits=(void*)0x7404;

// T2CON
volatile union T2CON_REG *T2CONbits=(void*)0x7408;

//T3CON
volatile union T3CON_REG *T3CONbits=(void*)0x7504;

//T4CON
volatile union T4CON_REG *T4CONbits=(void*)0x7508;

// EVAIMRA
volatile union EVAIMRA_REG *EVAIMRAbits=(void*)0x742C;

//EVAIMRB
volatile union EVAIMRB_REG *EVAIMRBbits=(void*)0x742D;

// EVAIMRC
volatile union EVAIMRC_REG *EVAIMRCbits=(void*)0x742E;

// EVBIMRA
volatile union EVBIMRA_REG *EVBIMRAbits=(void*)0x752C;

// EVBIMRB
volatile union EVBIMRB_REG *EVBIMRBbits=(void*)0x752D;

// EVBIMRC
volatile union EVBIMRC_REG *EVBIMRCbits=(void*)0x752E;

// EVAIFRA 
volatile union EVAIFRA_REG *EVAIFRAbits=(void*)0x742F;

//EVAIFRB
volatile union EVAIFRB_REG *EVAIFRBbits=(void*)0x7430;

// EVAIFRC
volatile union EVAIFRC_REG *EVAIFRCbits=(void*)0x7431;


//EVBIFRA
volatile union EVBIFRA_REG *EVBIFRAbits=(void*)0x752F;

// EVBIFRB
volatile union EVBIFRB_REG *EVBIFRBbits=(void*)0x7530;

// EVBIFRC
volatile union EVBIFRC_REG *EVBIFRCbits=(void*)0x7531;



// COMCONA 
volatile union COMCONA_REG *COMCONAbits=(void*)0x7411;

// COMCONB
volatile union COMCONB_REG *COMCONBbits=(void*)0x7511;

// ACTRA
volatile union ACTRA_REG *ACTRAbits=(void*)0x7413;

// ACTRB
volatile union ACTRB_REG *ACTRBbits=(void*)0x7513;

// DBTCONA
volatile union DBTCONA_REG *DBTCONAbits=(void*)0x7415;

// DBTCONB
volatile union DBTCONB_REG *DBTCONBbits=(void*)0x7515;

// CAPFIFOA
volatile union CAPFIFOA_REG *CAPFIFOAbits=(void*)0x7422;

//CAPFIFOB
volatile union CAPFIFOB_REG *CAPFIFOBbits=(void*)0x7522;

// CAPCONA
volatile union CAPCONA_REG *CAPCONAbits=(void*)0x7420;

// CAPCONB
volatile union CAPCONB_REG *CAPCONBbits=(void*)0x7520;