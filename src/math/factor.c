#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define TRIAL_DIVISION

#ifdef TRIAL_DIVISION
void factors(int N)
{
   int bound = (int)sqrtf((float)N);

   for ( int i=1; i<=bound; i++ ){
      if ( N%i == 0 ) printf("%d %d ", i, N/i);
   }

   printf("\n");
}
#endif


int main(){

   int N = 1024;

   factors(N);

   return 0;
}
