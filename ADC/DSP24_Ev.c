// ******************************************************************
// *																*
// *                TMS320LF2407A  event manager & Timer registers  *
// *                       C file                                   *
// *                  George Terzakis 2009                          *
// *															    *
// ******************************************************************

#include "DSP24_Ev.h"

// GPTCONA
volatile union GPTCONA_REG *GPTCONAbits=(void*)0x7400;
// GPTCONB
volatile union GPTCONB_REG *GPTCONBbits=(void*)0x7500;
//T1CON
volatile union T1CON_REG *T1CONbits=(void*)0x7404;
//T2CON
volatile union T2CON_REG *T2CONbits=(void*)0x7408;
//T3CON
volatile union T3CON_REG *T3CONbits=(void*)0x7504;
//T4CON
volatile union T4CON_REG *T4CONbits=(void*)0x7508;
// DBTCONA
volatile union DBTCONA_REG *DBTCONAbits=(void*)0x7415;
// DBTCONB
volatile union DBTCONB_REG *DBTCONBbits=(void*)0x7515;
// COMCONA
volatile union COMCONA_REG *COMCONAbits=(void*)0x7411;
// COMCONB
volatile union COMCONB_REG *COMCONBbits=(void*)0x7511;
// ACTRA
volatile union ACTRA_REG *ACTRAbits=(void*)0x7413;
// ACTRB
volatile union ACTRB_REG *ACTRBbits=(void*)0x7513;
//CAPCONA
volatile union CAPCONA_REG *CAPCONAbits=(void*)0x7420;
// CAPCONB
volatile union CAPCONB_REG *CAPCONBbits=(void*)0x7520;
// EVAIMRA
volatile union EVAIMRA_REG *EVAIMRAbits=(void*)0x742C;
// EVBIMRA
volatile union EVBIMRA_REG *EVBIMRAbits=(void*)0x752C;
// EVAIMRB
volatile union EVAIMRB_REG *EVAIMRBbits=(void*)0x742D;
// EVBIMRB
volatile union EVBIMRB_REG *EVBIMRBbits=(void*)0x752D;
// EVAIMRC
volatile union EVAIMRC_REG *EVAIMRCbits=(void*)0x742E;
// EVBIMRC
volatile union EVBIMRC_REG *EVBIMRCbits=(void*)0x752E;
//EVAIFRA
volatile union EVAIFRA_REG *EVAIFRAbits=(void*)0x742F;
//EVBIFRA
volatile union EVBIFRA_REG *EVBIFRAbits=(void*)0x752F;
// EVAIFRB
volatile union EVAIFRB_REG *EVAIFRBbits=(void*)0x7430;
// EVBIFRB
volatile union EVBIFRB_REG *EVBIFRBbits=(void*)0x7530;
// EVAIFRC
volatile union EVAIFRC_REG *EVAIFRCbits=(void*)0x7431;
// EVBIFRC
volatile union EVBIFRC_REG *EVBIFRCbits=(void*)0x7531;
// CAPFIFOA
volatile union CAPFIFOA_REG *CAPFIFOAbits=(void*)0x7422;
//CAPFIFOB
volatile union CAPFIFOB_REG *CAPFIFOBbits=(void*)0x7522;
