// TITLE: reverse string
// TAG: string
// LEVEL: easy

#include<stdio.h>

void swapChar( char *x, char *y )
{
   if ( x != y ){
      *x ^= *y;
      *y ^= *x;
      *x ^= *y;
   }
}



void reverseString( char *s, int sSize){

   int left = 0;
   int right = sSize-1;

   while( left+1 < right )   swapChar( &s[left], &s[right] );


}

int main(){

  char s[] = "abcdefghijklmn";

  printf("%s\n", s);

  reverseString(s);

  printf("%s\n", s);

  return 0;
}
