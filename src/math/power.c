// TITLE: Pow(x, n)
// LEVEL: medium
// TAG: bit-wise, power

#include <stdio.h>
#include <stdlib.h>

// Two's complement representation of signed integer
// 000   0
// 001   1
// 010   2
// 011   3
// 100  -4
// 101  -3
// 110  -2
// 111  -1


double myPow( double x, int n ){


   int sign = ( n > 0 ) ? 1 : -1 ;
   unsigned int absn = (unsigned int)n*sign ;
   double result = 1.0;
   double xPower = x;

   while(absn){

      if (absn&1)    result *= xPower;

      xPower *= xPower;

      absn    >>= 1;
   }


   return ( n > 0 ) ? ( result ) : ( 1.0/result );
}



int main(){

   double x = 5;
   int n = 5;

   printf("%.5f\n", myPow(x, n));
}
