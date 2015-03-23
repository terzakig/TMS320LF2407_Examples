
//************************************************************
//*                                                          *
//*   ALL TMS320LF2407A ISRs defined (look DefaultIsr.c for  *
//*   implementations)									     *
//*                                                          *
//*                  George Terzakis 2009                    *
//*                                                          *
//************************************************************


#ifndef DSP24_DEFAULT_ISR_H
#define DSP24_DEFAULT_ISR_H

//*************************************************************
// Default Interrupt Service Routine Declarations:
// 
// Go to PieVect for a structure containg all the vectors
// for the following ISRs
//*************************************************************

// ***************LEVEL 1 interrupts **********************
// **********(including CPU INT1 interrupt)****************

extern interrupt void INT1_GISR(void); // GISR for all INT1 level peripherals
// Now here comes all Specific ISRs...
// 1) Power drvive Protection Interrupt pin A
extern interrupt void PDPINTA_ISR(void);
// 2) Power Drive Protection interrupt pin B
extern interrupt void PDPINTB_ISR(void);
// 3) ADC interrupt in high priority
extern interrupt void ADCINT_HP_ISR(void);
// 4) External pin1 interrupt in high priority
extern interrupt void XINT1_HP_ISR(void);
// 5) External pin2 interrupt in high priority
extern interrupt void XINT2_HP_ISR(void);
// 6) SPI interrupt in high priority
extern interrupt void SPIINT_HP_ISR(void);
// 7) SCI Receive (Rx) interrupt in high priority
extern interrupt void RXINT_HP_ISR(void);
// 8) SCI Transmit (Tx) interrupt in high priority
extern interrupt void TXINT_HP_ISR(void);
// 9) CAN mailbox interrupt in high priority
extern interrupt void CANMBINT_HP_ISR(void);
// 10) CAN Error interrupt in high priority
extern interrupt void CANERINT_HP_ISR(void);

// ***************LEVEL 2 interrupts **********************
// **********(including CPU INT2 interrupt)****************
extern interrupt void INT2_GISR(void);// GISR for all INT2 level peripherals
// Now here comes all specific ISRs...

// 1) Compare 1 Interrupt
extern interrupt void CMP1INT_ISR(void);
// 2) Compare 2 interrupt
extern interrupt void CMP2INT_ISR(void);
// 3) Compare 3 Interrupt
extern interrupt void CMP3INT_ISR(void);
// 4) Timer 1 Period interrupt
extern interrupt void T1PINT_ISR(void);
// 5) Timer 1 Compare interrupt
extern interrupt void T1CINT_ISR(void);
// 6) Timer 1 Underflow interrupt
extern interrupt void T1UFINT_ISR(void);
// 7) Timer 1 Overflow interrupt
extern interrupt void T1OFINT_ISR(void);
// 8) Compare 4 interrupt
extern interrupt void CMP4INT_ISR(void);
// 9) Compare 5 interrupt
extern interrupt void CMP5INT_ISR(void);
// 10) Compare 6 interrupt
extern interrupt void CMP6INT_ISR(void);
// 11) Timer 3 Period interrupt
extern interrupt void T3PINT_ISR(void);
// 12) Timer 3 Compare interrupt
extern interrupt void T3CINT_ISR(void);
// 13) Timer 3 Underflow interrupt
extern interrupt void T3UFINT_ISR(void);
// 14) Timer 3 Overflow interrupt
extern interrupt void T3OFINT_ISR(void);

// ***************LEVEL 3 interrupts **********************
// **********(including CPU INT3 interrupt)****************
extern interrupt void INT3_GISR(void);// GISR for all INT3 level peripherals
// Now here comes all specific ISRs...

//1) Timer 2 Period interrupt
extern interrupt void T2PINT_ISR(void);
//2) Timer 2 Compare interrupt
extern interrupt void T2CINT_ISR(void);
//3) Timer 2 Underflow interrupt
extern interrupt void T2UFINT_ISR(void);
//4) Timer 2 Overflow interrupt
extern interrupt void T2OFINT_ISR(void);
//5) Timer 4 Period interrupt
extern interrupt void T4PINT_ISR(void);
//6) Timer 4 Compare interrupt
extern interrupt void T4CINT_ISR(void);
//7) Timer 4 Underflow interrupt
extern interrupt void T4UFINT_ISR(void);
//8) Timer 4 Overflow interruopt
extern interrupt void T4OFINT_ISR(void);

// ***************LEVEL 4 interrupts **********************
// **********(including CPU INT4 interrupt)****************
extern interrupt void INT4_GISR(void);// GISR for all INT4 level peripherals
// Now here comes all specific ISRs...

//1) Capture 1 interrupt
extern interrupt void CAP1INT_ISR(void);
//2) Capture 2 interrupt
extern interrupt void CAP2INT_ISR(void);
//3) Capture 3 interrupt
extern interrupt void CAP3INT_ISR(void);
//4) Capture 2 interrupt
extern interrupt void CAP4INT_ISR(void);
//5) Capture 5 interrupt
extern interrupt void CAP5INT_ISR(void);
//6) Capture 6 interrupt
extern interrupt void CAP6INT_ISR(void);

// ***************LEVEL 5 interrupts **********************
// **********(including CPU INT5 interrupt)****************
extern interrupt void INT5_GISR(void);// GISR for all INT5 level peripherals
// Now here comes all specific ISRs...

//1) SPI interrupt in low priority
extern interrupt void SPIINT_LP_ISR(void);
//2) SCI receive (RX) interrupt in low priority
extern interrupt void RXINT_LP_ISR(void);
//3) SCI Transmit (Tx) interrupt in low priority
extern interrupt void TXINT_LP_ISR(void);
//4) CAN mailbox interrupt in low priority
extern interrupt void CANMBINT_LP_ISR(void);
//5) CAN Error interrupt in low priority
extern interrupt void CANERINT_LP_ISR(void);

// ***************LEVEL 6 interrupts **********************
// **********(including CPU INT6 interrupt)****************
extern interrupt void INT6_GISR(void);// GISR for all INT6 level peripherals
// Now here comes all specific ISRs...

//1) ADC interrupt in low priority
extern interrupt void ADC_LP_ISR(void);
//2) External pin1 interrupt in low priority
extern interrupt void XINT1_LP_ISR(void);
//3) External pin 2 interrupt in low priority
extern interrupt void XINT2_LP_ISR(void);



// And that's it. We only have 6 maskable interrupts
// we pretty much covered them all i guess...


#endif    // end 
