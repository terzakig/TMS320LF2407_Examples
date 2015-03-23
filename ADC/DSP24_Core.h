/* ***************************************************************
 * A C Header for the CPU core registers of TMS320LF2407A *
 *																 *
 *                     George Terzakis  2009                     *
 *****************************************************************
*/

#ifndef DSP24_CORE_H
#define DSP24_CORE_H


// Core Register Bit Definitions:




struct IFR_BITS {     // bits  description
	unsigned int  INT1FLAG:1; // 0 Interrupt level 1 pending (1 for pending 0 not)
	unsigned int  INT2FLAG:1; // 1 Interrupt level 2 pending (1 for pending 0 not)
	unsigned int  INT3FLAG:1; // 2 Interrupt level 3 pending (1 for pending 0 not)
	unsigned int  INT4FLAG:1; // 3 Interrupt level 4 pending (1 for pending 0 not)
	unsigned int  INT5FLAG:1; // 4 Interrupt level 5 pending (1 for pending 0 not)
	unsigned int  INT6FLAG:1; // 5 Interrupt level 6 pending (1 for pending 0 not)
	unsigned int  rsvd1:10;  // 15-6 reserved
};


union IFR_REG {
   unsigned int             all;
   struct IFR_BITS  bit; 
};
extern volatile union IFR_REG *IFRbits;



struct IMR_BITS {     // bits  description
	unsigned int  INT1MASK:1; // 0 INTerrupt level 1 MASK bit (1 is UNmasked-acknowledged 0 masked-not acknownledged)
	unsigned int  INT2MASK:1; // 1 INTerrupt level 2 MASK bit (1 is UNmasked-acknowledged 0 masked-not acknownledged)
	unsigned int  INT3MASK:1; // 2 INTerrupt level 3 MASK bit (1 is UNmasked-acknowledged 0 masked-not acknownledged)
	unsigned int  INT4MASK:1; // 3 INTerrupt level 4 MASK bit (1 is UNmasked-acknowledged 0 masked-not acknownledged)
	unsigned int  INT5MASK:1; // 4 INTerrupt level 5 MASK bit (1 is UNmasked-acknowledged 0 masked-not acknownledged)
	unsigned int  INT6MASK:1; // 5 INTerrupt level 6 MASK bit (1 is UNmasked-acknowledged 0 masked-not acknownledged)
	unsigned int  rsvd1:10;  // 15-6 reserved
	
};


union IMR_REG {
   unsigned int             all;
   struct IMR_BITS  bit; 
};
extern volatile union IMR_REG *IMRbits;

// *************************************************
// WatchDog Control Register
// 
// 
// WDCR 
struct WDCTRL_BITS {  // bits  description
   unsigned int   WDPS:3;  // 0-2 WatchDog overflow frequency prescaling
   unsigned int   EDCHK0:1; // 3 WD CHEKbit0. Must be written 1 otherwise reset
   unsigned int   EDCHK1:1; // 4 WD CHEKbit1. Must be written 1 otherwise reset
   unsigned int   EDCHK2:1; // 5 WD CHEKbit2. Must be written 1 otherwise reset
   unsigned int   WDDIS:1;  // 6 WD Disabled (1). Write only when WD override bit is 1
   unsigned int   WDRSTFLAG:1; // 7 WD reset flag bit. It show if a reset occurred by the WD	
};

union WDCTRL_REG {
   unsigned int   all;
   struct WDCTRL_BITS  bit;
};
extern volatile union WDCTRL_REG *WDCTRLbits;

#endif