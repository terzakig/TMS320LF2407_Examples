// A simple "Hello" prgram. Turning on a pin by directly assigning values to registers (not in a bitwise fashion)
//
// George Terzakis 2009
//
// From the book: "Introduction to C programming with the TMS320LF2407 DSP Controller"

#define MCRA         (volatile unsigned int *)0x7090
#define PADATDIR     (volatile unsigned int *)0x7098
#define WDCR         (volatile unsigned int *)0x7029
#define SCSR2        (volatile unsigned int *)0x7019 
 


void main() {
     	 
  unsigned int i, temp, temp1;

  *SCSR2 = (*SCSR2 | 0x000B) & 0x000F; 

  *WDCR  = 0x00E8; // disable the watchdog

  *MCRA &= 0xFFFC; // set PortA General Pins 0 and 1 
                   // to General I/O function

  *PADATDIR|=0x0303; // Port A0, A1 bits output and 'high'
  /* main loop */
  while (1) {
    for(i=1;i<=1000;i++); // delay loop
   
   // store PADATDIR in temp
   temp = *PADATDIR;
   // store PADATDIR & 3 in temp1 
   temp1 = temp & 3;
   if (temp1 ==0)
   		temp |= 0x0003; // set bits 0, 1 = 1
    else 
    	temp &= 0xFFFC; // set bits 0, 1 = 0
   // copy temp to PADATDIR
   *PADATDIR = temp; 
  }
}
