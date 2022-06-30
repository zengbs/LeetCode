#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SIEVE_OF_ERATOSTHENES


void factors_trial_division(int N)
{
   int bound = (int)sqrtf((float)N);

   for ( int i=2; i<=bound; i++ ){
      if ( N%i == 0 ) printf("%d %d ", i, N/i);
   }

   printf("\n");
}


// Check the N is prime or not
void isPrimeTrialDivision( int N )
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


#ifdef SIEVE_OF_ERATOSTHENES
void FindPrimes(int N)
{
   bool *isPrimeArray = (bool*)malloc( (N+1)*sizeof(bool) );

   // initialization
   isPrimeArray[0] = isPrimeArray[1] = false;
   for ( int i=2;i<=N;i++ ) isPrimeArray[i] = true;

   // perform Sieve of Eratosthenes
   int bound = (int)sqrtf((float)N);

   for (int i=2;i<=bound;i++){

      if (isPrimeArray[i] == false) continue;

      int j = i*i;

      while( j<=N ) { isPrimeArray[j] = false; j += i;}

   }

   // print results
   for ( int i=2;i<=N;i++ )
      if (isPrimeArray[i])
         printf("%d ", i);

   printf("\n");
}
#endif

int main(){

   int N = 15345;

   factors_trial_division(N);
   FindPrimes(N);

   return 0;
}
