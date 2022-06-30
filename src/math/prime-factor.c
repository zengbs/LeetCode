#include <stdio.h>
#include <math.h>

void PrimeFactor( int N )
{

   int bound = (int)sqrtf( (float)N );

   int c = 2;

   for ( int i=2; i<=N; i++ ){

      if ( N%c == 0 ){

         printf("%d ", c);

         // do not divide c further when no factor c is in N
         while( N>1 && N%c==0 )  N /= c;
      }

      c++;
   }

   printf("\n");
}




int main()
{
  int n = 135464;
  PrimeFactor(n);
  return 0;
}
