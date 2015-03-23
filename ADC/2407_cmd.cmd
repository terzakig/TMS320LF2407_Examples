/*********************************************************************
* Filename: example_c.cmd                                            *
*                                                                    *
* Author: David M. Alter, Texas Instruments Inc.                     *
*                                                                    *
* Last Modified: 03/14/01                                            *
*                                                                    *
* Description: C code linker command file for LF2407 DSP.            *
*********************************************************************/


MEMORY
{
  PAGE 0:    /* Program Memory */
    VECS:           org=00000h,   len=00040h   /* internal FLASH */
    FLASH:          org=00044h,   len=07FBCh   /* internal FLASH */
    EXTPROG:        org=08800h,   len=07800h   /* external SRAM  */

  PAGE 1:    /* Data Memory */
    B2:             org=00060h,   len=00020h   /* internal DARAM */
    B0:             org=00200h,   len=00100h   /* internal DARAM */
    B1:             org=00300h,   len=00100h   /* internal DARAM */
    SARAM:          org=00800h,   len=00800h   /* internal SARAM */
    EXTDATA:        org=08000h,   len=08000h   /* external SRAM  */
}

SECTIONS
{
/* Sections generated by the C-compiler */
        .text:  >   EXTPROG    PAGE 0   /* initialized */
       .cinit:  >   EXTPROG    PAGE 0   /* initialized */
       .const:  >   B1         PAGE 1   /* initialized */
      .switch:  >   EXTPROG    PAGE 0   /* initialized */
         .bss:  >   EXTDATA         PAGE 1   /* uninitialized */
       .stack:  >   SARAM      PAGE 1   /* uninitialized */
      .sysmem:  >   B1         PAGE 1   /* uninitialized */

/* Sections declared by the user */
      vectors:  >   VECS       PAGE 0   /* initialized */
}

