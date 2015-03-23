// Using a C-callable assembly function (convolution) 
//
// George Terzakis 2009
//
// From the book: "Introduction to C programming with the TMS320LF2407 DSP Controller"


extern void convolve(int*, int*, int, int, int*, int*);




void main(void) {

int h[] = {1, 1, 1};
int x[] = {4, 3, 2};
int ach, acl;





convolve(&h[2], &x[2], 2, 5, &acl, &ach);

while (1) {

}

}