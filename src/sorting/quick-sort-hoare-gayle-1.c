#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void xorSwap( int *a, int *b );


int partition(int *arr, int l, int r)
{
   int l0 = l;
   int r0 = r;
   int p = (l+r)/2; // pick an arbitrary element as a pivot
       p = (p+r)/2;
       p = (p+r)/2;
       p = r;
   int pivot = arr[p]; // pick pivot point

   while ( l <= r ){

      //    skip the elements that should be on left
      //    but stop at the element that should be on right
      while (arr[l] < pivot) l++;

      //    skip the elements that should be on right
      //    but stop at the element that should be on left
      while (arr[r] > pivot) r--;

      // swap elements, and move left and right indices
      if ( l <= r )  xorSwap(&arr[l++], &arr[r--]);
   }


   return r;
}


// usage:  quickSort(arr, 0, arrSize-1);
void quickSort(int *arr, int l, int r)
{
   // base case
   if ( r <= l ) return;

   int q = partition(arr, l, r);

   quickSort(arr, l, q);

   quickSort(arr, q+1, r);

}
