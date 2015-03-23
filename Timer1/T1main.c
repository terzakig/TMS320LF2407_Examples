// Configuring and using Timer #1
//
// George Terzakis 2009
//
// From the book: "Introduction to C programming with the TMS320LF2407 DSP Controller"

extern void initSystem(void);
extern void initTimer1(void);

void main() {
     
     int i;
     
     initSystem();     
	 initTimer1();

	 asm(" CLRC INTM");   // enable Interrupts
	 while (1) {
	 }
}
     

