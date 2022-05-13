// https://youtu.be/duln2xAZhBA

#include <stdio.h>
#include "../include/array.h"

void xorSwap( int *a, int *b ){
   if ( *a != *b ){
      *a ^= *b;
      *b ^= *a;
      *a ^= *b;
   }
}


int partition(int *arr, int l, int r){

   int pivot = l + (r-l)/2;

   xorSwap( &arr[pivot], &arr[r] );

   int i = l;

   for ( int j=l; j<r; j++ ){
      if ( arr[j] < arr[r] ){
         xorSwap(&arr[i], &arr[j]);
         i++;
      }
   }

   xorSwap(&arr[i], &arr[r]);

   return i;
}

void QuickSort(int *arr, int l, int r){

    if (r <= l) return;

    int pivot = partition(arr, l, r);

    QuickSort(arr, l, pivot - 1);
    QuickSort(arr, pivot + 1, r);
}


int main() {

    int arr[] = {1,7,2,5, 9, 3, 10,-1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("original:\n");
    printArray(arr, n);

    QuickSort(arr, 0, n-1);

    printf("sorted:\n");
    printArray(arr, n);
    return 0;
}
