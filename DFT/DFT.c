#include "Globals.h"

// computation of the frequency domain signals
void computeDFT(unsigned int x[], unsigned int Re[], unsigned int Im[], unsigned int Nn) {
   int k, n;
   float R, I;
   for (k = 0; k < Nn / 2 + 1; k++) {
       R = I = 0;
       for (n = 0; n < Nn; n++) {
          R += x[n] * cos(2 * PI * n *k / (1.0*N));
          I += x[n] * sin(2 * PI * n *k / (1.0*N));
        }
        R = ((k==0) || k==N/2) ? Re[k]/Nn : Re[k] * 2.0 / Nn;
        I= ((k==0) || k==Nn/2) ? Im[k]/Nn : Im[k] * 2.0 / Nn;
		ReX[k] = (unsigned int)R;
		ImX[k] = (unsigned int)I;
      }
}

