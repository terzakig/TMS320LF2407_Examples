# Example C-programs for operating the peripherals of TMS320LF2407 DSP Controller (EzDSP2407)

This reposiroty contains a complete set of examples for every peripheral of the TMS320LF2407 in C. It also contains two examples on filtering (IIR and FIR) and one on the FFT. These examples are explained in the book, [**Introduction to C programming with the TMS320LF2407 DSP Controller**](https://www.amazon.com/Introduction-Programming-TMS320LF2407ATM-DSP-Controller/dp/145658880X).

Although the [TMS320LF2407](http://c2000.spectrumdigital.com/evmlf2407a/docs/evmlf2407a_techref.pdf) is traditionally programmed in assembly in order to fully exploit its special instruction set of optimal performance in standard DSP operations, there is no reason to write peripheral initialization in assembly. Furthermore, as it shown in [this example](https://github.com/terzakig/TMS320LF2407_Examples/tree/master/AsmFunc), it is possible to write _C-callable assembly functions_. Thus, the actual DSP algorithm can be optimized with C-callable assmebly functions wherever necessary.  

Each example contains minimal-sized header files that provide C-structure wrappers for the necessary register's and interrupt service routines (ISRs). To access a complete set of header files including a full list of interrupt service routines (file 'DSP24_DefaultIsr.h'), refer to [this repository](https://github.com/terzakig/TMS3202407_C_Headers).



