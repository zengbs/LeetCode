// https://youtu.be/duln2xAZhBA

#include <stdio.h>

void xorSwap( int *a, int *b );


int partition(int *arr, int l, int r){

   // choose the rightmost element as pivot.
   int pivot = r;

   int i = l;
   for ( int j=l; j<r; j++ ){
      if ( arr[j] < arr[pivot] )  xorSwap(&arr[i++], &arr[j]);
   }

   xorSwap(&arr[i], &arr[r]);

   // return the current index of pivot
   return i;
}

// usage : quickSort(arr, 0, arrSize-1);
void quickSort(int *arr, int l, int r){

#  ifdef TAIL_RECURSIVE
   // base case
   if (r <= l) return;

   int pivot = partition(arr, l, r);

   quickSort(arr, l, pivot - 1);
   quickSort(arr, pivot + 1, r);
#  else
   while( l < r ){

      int pivot = partition(arr, l, r);

      quickSort(arr, l, pivot - 1);

      l = pivot + 1;

   }
#  endif
}
