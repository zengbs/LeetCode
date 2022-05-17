#include<stdio.h>


void xorSwap( int *a, int *b );

void insertionSort( int *arr, int arrSize ){

   for ( int i=1; i<arrSize; i++ ){

      if ( arr[i] < arr[i-1] ){

         int j = i;

         do{

            xorSwap( &arr[j], &arr[j-1] );

            j--;

         }while( j>0 &&  arr[j-1] > arr[j] );

      }
   }
}
