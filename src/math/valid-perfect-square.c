// TITLE: Valid Perfect Square
// LEVEL: easy
// TAG: bit-wise, binary-search

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool isPerfectSquare(int num){

   if      ( num  > 46340*46340 ) return false;
   else if ( num == 46340*46340 ) return true;

   int l = 0;
   int r = 46340;

   while( l+1 != r ){

      int m = l + (r-l)/2;
      int mSqr = m*m;

      if      ( mSqr < num ) l = m;
      else if ( num < mSqr ) r = m;
      else                return true;

   }

   return false;
}


int main(){

   int x = 1024;

   printf("%d\n", isPerfectSquare(x));

}
