// https://youtu.be/duln2xAZhBA

#include <stdio.h>

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
      if ( arr[j] < arr[r] )  xorSwap(&arr[i++], &arr[j]);
   }

   xorSwap(&arr[i], &arr[r]);

   return i;
}

// usage : quickSort(arr, 0, arrSize-1);
void quickSort(int *arr, int l, int r){

    if (r <= l) return;

    int pivot = partition(arr, l, r);

    quickSort(arr, l, pivot - 1);
    quickSort(arr, pivot + 1, r);
}
