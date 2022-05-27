// TITLE: reverse string ||
// TAG: string
// LEVEL: easy

#include<stdio.h>

void swap( char *x, char *y ){

   if ( x != y ){
      *x ^= *y;
      *y ^= *x;
      *x ^= *y;
   }
}


char * reverseEntireStr(char * s, int sSize)
{
   int left = 0;
   int right = sSize-1;
   int count = 0;

   while( count < sSize/2 ){
      swap( &s[left], &s[right] );
      left++; right--; count++;
   }
   return s;
}


//  0 <  L < k
//  k <= L < 2k
// 2k <= L

// 1 2 3 4 5 6
// a b c d e f
char * reverseStr(char * s, int k){

   int stringLength=0;
   for (int i=0; s[i] != '\0'; i++) stringLength++;

   for ( int i=0; i<stringLength; i+=2*k ){
      if ( i+k < stringLength ){
         reverseEntireStr( &s[i], k );
      }
      else{
         reverseEntireStr( &s[i], stringLength-i );
      }
   }
   return s;
}

int main(){

   char s[] = "lwhefwheflf";

   int k = 3;

   printf( "%s\n", s);
   printf( "%s\n", reverseStr(s, k));

   return 0;
}
