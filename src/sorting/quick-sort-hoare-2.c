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
   int p = (r+l)/2;
       p = (p+l)/2;
       p = r;
   int pivot = arr[p];

   int i = l - 1;
   int j = r + 1;


   while (1){
//if ( j < l || r < j ) printf("l=%d, j=%d, r=%d\n",l, j, r);
      //    skip the elements that should be on right
      //    but stop at the element that should be on left
      //while( arr[j] > pivot ) j--;// not works. why?
      do{ j--; } while (arr[j] > pivot);

//if ( i < l || r < i ) printf("l=%d, i=%d, r=%d\n",l, i, r);
      //    skip the elements that should be on left
      //    but stop at the element that should be on right
      //while( arr[i] < pivot ) i++;// not works
      do{ i++; } while (arr[i] < pivot);

      // is the order of `l++` and `r--` important? no

      // swap elements, and move left and right indices
      if ( i < j )  xorSwap(&arr[i], &arr[j]);
      else          return i;
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
   quickSort(arr, l, q-1);

   //step-2: sort right half
   quickSort(arr, q, r);

   // is the order of `step-1` and `step-2` important? no
}
