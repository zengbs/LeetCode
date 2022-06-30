#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define TRIAL_DIVISION

# ifdef TRIAL_DIVISION
void IsPrime( int N )
{
   int bound = (int)sqrtf((float)N);

   if      ( N   == 2 ) { printf("%d is a prime!\n"    , N); return; }

   else if ( N%2 == 0 ) { printf("%d is not a prime!\n", N); return; }

   else{

      for ( int i=2; i<=bound; i++ ){
         if ( N%i == 0 ) {
            printf("%d is not a prime!\n", N);
            return;
         }
      }

      printf("%d is a prime!\n", N);
   }

   printf("\n");
}
#endif


int main(){

   int N = 17;

   IsPrime(N);

   return 0;
}
