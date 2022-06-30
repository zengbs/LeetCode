#include<stdio.h>
#include<math.h>

#define RECURSION

#ifdef ITERATION
int Fibonacci( int n )
{
   if (n==0) return 0;
   if (n==1) return 1;

   int a = 0;
   int b = 1;
   int c;

   for ( int i=0; i<=n-2; i++ ){
      c = a + b;
      a = b;
      b = c;
   }

   return c;

}
#endif

#ifdef RECURSION
int Fibonacci( int n )
{
   if ( n == 0  ) return 0;
   if ( n == 1  ) return 1;

   return Fibonacci( n-2 ) + Fibonacci( n-1 );
}
#endif


int main(){

   for (int i=0;i<20;i++)   printf("%d ", Fibonacci(i));

   printf("\n");

   return 0;
}
