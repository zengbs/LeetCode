// TITLE:
// LEVEL:
// TAG: array, hash, gcd

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// a % b = c
// b % c = d
// c % d = e
//   .
//   .
//   .
// if ( e == 0 ) gcd = c;

int __gcd( int a, int b ){

   if ( b == 0 ) return a;

   return __gcd( b, a%b );
}


bool hasGroupsSizeX(int* deck, int deckSize){

   int max = INT_MIN;

   for ( int i=0;i<deckSize;i++ ){
      if ( max < deck[i] ) max = deck[i];
   }


   int *counter = (int*)calloc(max+1, sizeof(int));

   for ( int i=0;i<deckSize;i++ ){
      counter[ deck[i] ]++;
   }

   int gcd = counter[0];

   for ( int i=1;i<max+1;i++ ){
      gcd = __gcd( counter[i], gcd );
   }

   if (gcd > 1) return true;
   else         return false;
}


int main(){

   int deck[] = {1,2,3,5,5,3,2,1, 5, 4};

   printf("%d\n", hasGroupsSizeX( deck, sizeof(deck)/sizeof(deck[0]) ));

   return 0;
}

