
#ifndef DSP24_DEVICE_H
#define DSP24_DEVICE_H

#define  EINT   asm(" clrc INTM")
#define  DINT   asm(" setc INTM")


// #include "DSP28_GlobalPrototypes.h"   // Prototypes for global functions within the 
                                      // .c files.

#include "DSP24_Core.h"    // Core registers
#include "DSP24_PieSys.h"    // PIE Control Registers
#include "DSP24_DefaultIsr.h" // All SISRs (addcode) and GISRs
#include "DSP24_Spi.h"        // SPI Registers
#include "DSP24_Sci.h"        // SCI Registers
#include "DSP24_Can.h"       // CAN Registers (control and status for now...)
#include "DSP24_Gpio.h"       // General Purpose I/O Registers
#include "DSP24_Ev.h"         // Event Manager Registers
#include "DSP24_Adc.h"        // ADC Registers
#include "DSP24_XIntrupt.h"   // External Interrupts
#include "f2407_c.h"          // register definitions as unsigned integers



#endif   