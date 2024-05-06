#include<stdio.h>
#include<math.h>

#define ITERATION

#ifdef ITERATION
int Fibonacci( int n )
{
   if ( n == 0 ) return 0;
   if ( n == 1 ) return 1;

   int a = 0;
   int b = 1;
   int c = a+b;

   for( int i=2;i<n;i++ ){
      a = b;
      b = c;
      c = a + b;
   }

   return c;
}
#endif

#ifdef RECURSION
int Fibonacci( int n )
{
   if ( n == 0 ) return 0;
   if ( n == 1 ) return 1;

   // why not Fibonacci(n  )+Fibonacci(n-1) ?
   return Fibonacci(n-1)+Fibonacci(n-2);
}
#endif


int main(){

   for (int i=0;i<10;i++)   printf("%d ", Fibonacci(i));

   printf("\n");

   return 0;
}
