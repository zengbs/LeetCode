// =============================
// Description:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getPivot( int *arr, int l0, int r0 );

void xorSwap( int *a, int *b );


int partition(int *arr, int l0, int r0)
{

   // pick an arbitrary pivot except for arr[l0]
   int pivot = getPivot( arr, l0+1, r0 );


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
      else          return l;
   }
}


// usage:  quickSort(arr, 0, arrSize-1);
void quickSort(int *arr, int l, int r)
{

   // base case
   if ( r <= l ) return;

   int q = partition(arr, l, r);

   // step-1: sort left half
   quickSort(arr, l, q-1);

   //step-2: sort right half
   quickSort(arr, q, r);

}

