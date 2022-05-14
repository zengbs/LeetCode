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

   // pick an arbitrary pivot index
   int pivotIdx = (r+l)/2;
       pivotIdx = (pivotIdx+l)/2;

   int pivot = arr[pivotIdx];

   int i = l - 1;
   int j = r + 1;


   while (1){

      //    skip the elements that should be on right
      //    but stop at the element that should be on left
      //while( arr[j] > pivot ) j--;// not works. why?
      do{ j--; } while (arr[j] > pivot);

      //    skip the elements that should be on left
      //    but stop at the element that should be on right
      //while( arr[i] < pivot ) i++;// not works
      do{ i++; } while (arr[i] < pivot);

      // is the order of `l++` and `r--` important? no

      // swap elements, and move left and right indices
      if ( i < j )  xorSwap(&arr[i], &arr[j]);
      else          return j;
   }

// Question:
// b. The indices i and j are such that we never access an element of A outside the
//    subarray A[l..r].
// c. When partition terminates, it returns a value j such that l ≤ j < r.
//    since j minus 1 two time at least
//    since i plus  1 one time at least
// d. Every element of A[l..j] is less than or equal to every element of A[j+1 .. r]
//    when partition terminates.
}


// usage:  quickSort(arr, 0, arrSize-1);
void quickSort(int *arr, int l, int r)
{

   if ( r <= l ) return;

   int q = partition(arr, l, r);

   // step-1: sort left half
   quickSort(arr, l, q);

   //step-2: sort right half
   quickSort(arr, q+1, r);

   // is the order of `step-1` and `step-2` important? no
}

