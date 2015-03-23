//****************************************************************
//
//          TMS320LF2407A external interrupt registers 
//			
//					George Terzakis 2009
//
//****************************************************************


#ifndef DSP24_XINTRUPT_H
#define DSP24_XINTRUPT_H

//---------------------------------------------------------------------------
//  External Interrupt Control registers
//
//   XINT1CR

struct XINT1CTRL_BITS {
    unsigned int   ENABLE:1;    // 0      enable/disable
    unsigned int   XINT1PRI:1;     // 1   XINT1 Priority (0 HIGH, 1 LOW)
    unsigned int   POLARITY:1;  // 2      pos/neg triggered
    unsigned int   rsvd:11;    // 14:3   reserved
	unsigned int   FLAG:1;   //15 It goes high after a trigger on th pin is detected (must be set 0 by the ISR)
};

union XINT1CTRL_REG {
   unsigned int               all;
   struct XINT1CTRL_BITS   bit;
};  
extern volatile union XINT1CTRL_REG *XINT1CTRLbits;



//---------------------------------------------------------------------------
//  External Interrupt Control registers
//
//   XINT2CR

struct XINT2CTRL_BITS {
    unsigned int   ENABLE:1;    // 0      enable/disable
    unsigned int   XINT2PRI:1;     // 1   XINT2 Priority (0 HIGH, 1 LOW)
    unsigned int   POLARITY:1;  // 2      pos/neg triggered
    unsigned int   rsvd:11;    // 14:3   reserved
	unsigned int   FLAG:1;   //15 It goes high after a trigger on th pin is detected (must be set 0 by the ISR)
};

union XINT2CTRL_REG {
   unsigned int               all;
   struct XINT2CTRL_BITS   bit;
};  
extern volatile union XINT2CTRL_REG *XINT2CTRLbits;




#endif  

