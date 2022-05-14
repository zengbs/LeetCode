#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void xorSwap( int *a, int *b ){
   if ( *a != *b ){
      *a ^= *b;
      *b ^= *a;
      *a ^= *b;
   }
}


int partition(int *arr, int l, int r)
{
   int pivotIdx = (l+r)/2; // pick an arbitrary element as a pivot
       pivotIdx = (pivotIdx+r)/2;
       pivotIdx = (pivotIdx+r)/2;
//pivotIdx = 0;
   int pivot = arr[pivotIdx]; // pick pivot point

   while ( l <= r ){

      // increase l:
      //    skip the elements that should be on left
      //    but stop at the element that should be on right
      while (arr[l] < pivot) l++;

      // decrease r:
      //    skip the elements that should be on right
      //    but stop at the element that should be on left
      while (arr[r] > pivot) r--;

      // is the order of `l++` and `r--` important? no
      // swap elements, and move left and right indices
      // `<=` is necessary, why?
      if ( l <= r )  xorSwap(&arr[l++], &arr[r--]);
   }

   return l;
}


// usage:  quickSort(arr, 0, arrSize-1);
void quickSort(int *arr, int l, int r)
{
   if ( r <= l ) return;

   int q = partition(arr, l, r);

   quickSort(arr, l, q-1);

   quickSort(arr, q, r);

   // is the order of `step-1` and `step-2` important? no
}
