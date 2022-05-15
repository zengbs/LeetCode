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


int partition(int *arr, int l0, int r0)
{

   // pick an arbitrary pivot index
   int p = (r0+l0)/2;
       p = (p +l0)/2;
       p = l0;
   int pivot = arr[p];

   int l = l0 - 1;
   int r = r0 + 1;


   while (1){
      //    skip the elements that should be on right
      //    but stop at the element that should be on left
      do{ r--; } while (arr[r] > pivot);

      //    skip the elements that should be on left
      //    but stop at the element that should be on right
      do{ l++; } while (arr[l] < pivot);


      // swap elements, and move left and right indices
      if ( l < r )  xorSwap(&arr[l], &arr[r]);
      else          return r;
   }


// Question:
// b. The indices i and j never access outside the subarray A[l..r].
// c. When partition terminates, it returns a value j such that l ≤ j < r.
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

}

