// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//#define SIEVE_OF_ERATOSTHENES
#define NAIVE

#ifdef NAIVE
bool isPrime( int N ){

   int flag = true;

   int bound = (int)sqrtf((float)N); // 3

   // i = 2,...,"bound"
   for (int i=2; i<=bound; i++){
      if ( N%i == 0 ){
         flag = false;
         break;
      }
   }

   return flag;
}

void FindPrimes( int N ){
   for ( int i=2;i<=N;i++ ){
      if ( isPrime(i) ) printf( "%d\n", i );
   }
}

#endif

#ifdef SIEVE_OF_ERATOSTHENES
// Time complexity: O(N log log N)


void FindPrimes(int N)
{
   bool *isPrimeArray = (bool*)malloc( (N+1)*sizeof(bool) );

   // Initialization
   isPrimeArray[0] = isPrimeArray[1] = false;
   for ( int i=2;i<=N;i++ ) isPrimeArray[i] = true;

   // Perform Sieve of Eratosthenes
   // Why is `bound` sqrt(N)?
   // --> because j start from i*i
   int bound = (int)sqrtf((float)N);

   for (int i=2;i<=bound;i++){

      if (isPrimeArray[i] == false) continue;

      // Why does j start from i*i ?
      // --> because the multiples of i that are smaller than i*i has been remvoed previously
      int j = i*i;

      while( j<=N ) { isPrimeArray[j] = false; j += i;}

   }

   // Print results
   for ( int i=0;i<=N;i++ )
      if (isPrimeArray[i])
         printf("%d ", i);

   printf("\n");
}
#endif

int main(){

   int N = 153;

   FindPrimes(N);

   return 0;
}
