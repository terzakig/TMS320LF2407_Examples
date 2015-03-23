// PWM using the Compare unit
//
// George Terzakis 2009
//
// From the book: "Introduction to C programming with the TMS320LF2407 DSP Controller"

extern void initSystem(void);
extern void initPwm(void);

extern void initIO(void);

void main() {
     
     
     initSystem();     
	 
	 initIO();
	 
	 initPwm();

	 asm(" CLRC INTM");   // enable Interrupts
	 while (1) {
	 }
}
     

