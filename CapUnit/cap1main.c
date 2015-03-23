// Using the Capture Unit
//
// George Terzakis 2009
//
// From the book: "Introduction to C programming with the TMS320LF2407 DSP Controller"

extern void initSystem(void);

extern void initCap1(void);

extern void initIO(void);

void main() {
     
     
     initSystem();     
	 
	 initIO();
	
	 initCap1();
	 

	 asm(" CLRC INTM");   // enable Interrupts
	 while (1) {
	 }
}
     

