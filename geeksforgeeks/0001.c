// https://www.geeksforgeeks.org/maximum-difference-between-two-elements-in-an-array/

// TITLE: Maximum difference between two elements in an Array
// TAG  : array
// LEVEL: easy

// Given an array arr[] of N integers,
// the task is to find the maximum difference
// between any two elements of the array.

#include<stdio.h>

void function( int *arry, int arrySize, int *maxDiff, int *max, int *min ){

   *max = arry[0];
   *min = arry[0];

   for (int i=0; i<arrySize; i++){
      if ( *max < arry[i] )  *max = arry[i];
      if ( *min > arry[i] )  *min = arry[i];
   }

   *maxDiff = max - min;

}


#define N 6

int main(){

   int maxDiff, max, min;

   int arry[N] = { 1, 5, -6, -7, 0, 5 };

   function( arry, N, &maxDiff, &max, &min );

   printf( "maximum difference: %d\n", maxDiff );
   printf( "maximum element: %d\n",    max );
   printf( "maximum element: %d\n",    min );

   return 0;
}
