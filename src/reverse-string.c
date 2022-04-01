#include<stdio.h>



void swapChar(char *x, char *y)
{
  if (x != y)
  {
    *y ^= *x;
    *x ^= *y;
    *y ^= *x;
  }
}


void reverseString( char s[] ){

   int length = 0;

   // get string length excluded ‘\0’
   while( s[length] != '\0' ){   s[length];   length++;   }

   // length is odd
   if ( length & 1 )
   {
      for (int idx=0;idx<(length-1)/2;idx++) swapChar( s+idx, s+length-idx-1 );
   }
   // length is even
   else
   {
      for (int idx=0;idx<length/2    ;idx++) swapChar( s+idx, s+length-idx-1 );
   }
}

int main(){

  char s[] = "12345678";

  printf("%s\n", s);

  reverseString(s);

  printf("%s\n", s);

  return 0;
}
