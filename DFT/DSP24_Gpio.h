

#ifndef DSP24_GPIO_H
#define DSP24_GPIO_H

struct MCRA_BITS  {      // bits   description (MCRA)
   unsigned int SCITXD_GPIOA0:1;     // 0  PORTA0 if 0
   unsigned int SCIRXD_GPIOA1:1;     // 1 PORTA1  if 0
   unsigned int XINT1_GPIOA2:1;     // 2  PORTA2 if 0
   unsigned int CAP1QEP1_GPIOA3:1;     // 3 PORTA3 if 0
   unsigned int CAP2QEP2_GPIOA4:1;     // 4 PORTA4  if 0
   unsigned int CAP3_GPIOA5:1;     // 5 PORTA5 if 0
   unsigned int PWM1_GPIOA6:1;    // 6  PORTA6  if 0
   unsigned int PWM2_GPIOA7:1;    // 7 PORTA7  if 0     
   unsigned int PWM3_GPIOB0:1;   // 8 PORTB0   if 0
   unsigned int PWM4_GPIOB1:1;   // 9 PORTB1  if 0
   unsigned int PWM5_GPIOB2:1; // 10 PORTB2  if 0
   unsigned int PWM6_GPIOB3:1;   // 11 PORTB3 if 0
   unsigned int T1PWMT1CMP_GPIOB4:1; // 12 PORTB4 if 0
   unsigned int T2PWMT2CMP_GPIOB5:1;  // 13  PORTB5 if 0
   unsigned int TDIRA_GPIOB6:1;  // 14  PORTB6 if 0
   unsigned int TCLKINA_GPIOB7:1;  // 15 PORTB7 if 0
         
};

union MCRA_REG {
   unsigned int all;
   struct MCRA_BITS bit;
};
extern volatile union MCRA_REG *MCRAbits;


// MCRB
struct MCRB_BITS  {      
   unsigned int WR_GPIOC0:1;     // 0  PORTC0 if 0
   unsigned int BIO_GPIOC1:1;     // 1 PORTC1 if 0
   unsigned int SPISIMO_GPIOC2:1;     // 2  PORTC2 if 0
   unsigned int SPISOMI_GPIOC3:1;     // 3 PORTC3 if 0
   unsigned int SPICLK_GPIOC4:1;     // 4 PORTC4  if 0
   unsigned int SPISTE_GPIOC5:1;     // 5 PORTC5 if 0
   unsigned int CANTX_GPIOC6:1;    // 6  PORTC6 if 0
   unsigned int CANRX_GPIOC7:1;    // 7 PORTC7  if 0     
   unsigned int XINTADCSOC_GPIOD0:1;   // 8 PORTD0 if 0/XINT or ADC SOC
   unsigned int EMU0_rsvd:1;   // 9 reserved if 0/EMU0
   unsigned int EMU1_rsvd:1; // 10 reserved if 0/ EMU1
   unsigned int TCK_rsvd:1;   // 11 reserved if 0/ TCK
   unsigned int TDI_rsvd:1; // 12 reserved if 0/TDI 
   unsigned int TDO_rsvd:1;  // 13  reserved if 0/TDO
   unsigned int TMS_rsvd:1;  // 14  reserved if 0 / TMS
   unsigned int TMS2_rsvd:1;  // 15 reserved if 0 / TMS2
         
};

union MCRB_REG {
   unsigned int all;
   struct MCRB_BITS bit;
};
extern volatile union MCRB_REG *MCRBbits;



struct PADATDIR_BITS  {      // bits   description (PADATDIR)
   unsigned int IOPA0:1;     // 0  A0 data
   unsigned int IOPA1:1;          // 1 A1 data
   unsigned int IOPA2:1;          // 2 A2 data
   unsigned int IOPA3:1;          // 3  A3 data
   unsigned int IOPA4:1;          // 4  A4 data
   unsigned int IOPA5:1;          // 5  A5 data
   unsigned int IOPA6:1;          // 6  A6 data
   unsigned int IOPA7:1;          // 7  A7 data      
   unsigned int A0DIR:1;          // 8  A0 direction (0 input/1 output)
   unsigned int A1DIR:1;          // 9  A1 direction (0 input/1 output)
   unsigned int A2DIR:1;         // 10  A2 direction (0 input/1 output)
   unsigned int A3DIR:1;         // 11 A3 direction (0 input/1 output)
   unsigned int A4DIR:1;         // 12 A4 direction (0 input/1 output)
   unsigned int A5DIR:1;         // 13  A5 direction (0 input/1 output)
   unsigned int A6DIR:1;         // 14  A6 direction (0 input/1 output) 
   unsigned int A7DIR:1;         // 15  A7 direction (0 input/1 output)
         
};

union PADATDIR_REG {
   unsigned int all;
   struct PADATDIR_BITS bit;
};
extern volatile union PADATDIR_REG *PADATDIRbits;

#endif