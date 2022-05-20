// TITLE: Sqrt(x)
// LEVEL: easy
// TAG: bit-wise, binary-search

#include <stdio.h>
#include <stdlib.h>


int mySqrt(int x){

//46340 = mySqrt(INT_MAX)
  if(x >= 46340 * 46340) return 46340;


   int l = -1;
   int r = 46340;

   while( l+1 != r ){

      int m = l + (r-l)/2;
      int mSqr = m*m;
      if      ( mSqr < x ) l = m;
      else if ( x < mSqr ) r = m;
      else                 return m;
   }

   return l;
}



int main(){

   int x = 26;

   printf("%d\n", mySqrt(x));

}
