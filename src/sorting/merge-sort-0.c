// http://alrightchiu.github.io/SecondRound/comparison-sort-merge-sorthe-bing-pai-xu-fa.html
// https://hsm.stackexchange.com/questions/12549/how-did-von-neumann-come-up-with-his-merge-sort-algorithm


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "../include/array.h"

// merge two subarrays arr[l..m] and arr[m+1..r] into arr[l..r]
void merge(int arr[], int l, int m, int r)
{
   int left[m-l+2];  // m-(l-1)+1
   int right[r-m+1]; // r-m+1

   // copy arr[l...m] to left[0..m-l]
   for( int i=0; i<m-l+1; i++ )   left[i] = arr[l+i];


   // copy arr[m+1...r] to right[0..r-m-1]
   for( int i=0; i<r-m; i++ )     right[i] = arr[m+1+i];


   // append INT_MAX to left[] and right[]
   left[m-l+1] = INT_MAX; right[r-m] = INT_MAX;


   // create two indice for left[] and right[]
   int subl = 0;
   int subr = 0;

   for( int i=l; i<=r; i++ ){
      if ( left[subl] < right[subr] )  arr[i] = left[subl++];
      else                             arr[i] = right[subr++];
   }
}


// split arr[l..r] into arr[l..m] and arr[m+1..r]
void mergeSort(int arr[], int l, int r)
{
   // base case
   if ( r <= l ) return;

   // round m downward
   int m = l + (r - l) / 2;

   // split into left subarray
   mergeSort(arr, l, m);

   // split into right subarray
   mergeSort(arr, m + 1, r);

   // merge subsrrays
   merge(arr, l, m, r);
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}



int main()
{

  int arrSize = 30000;

   int *array     = (int*)malloc(arrSize*sizeof(int));
   int *array_ref = (int*)malloc(arrSize*sizeof(int));

   srand(time(NULL));

   for ( int i=0;i<arrSize;i++ ){
      array[i] = rand();
      array_ref[i] = array[i];
   }

   mergeSort(array, 0, arrSize-1);
   qsort (array_ref, arrSize, sizeof(int), compare);

   for ( int i=0;i<arrSize;i++ ){
      if ( array_ref[i] != array[i] ){
         printf("Fail!\n");
         return 0;
      }
   }

   printf("Pass!\n");
   return 0;

}

// Call stack:
//                       [(1  2  3)(4  5)]
//                       merge(0, 2, 4)      0  2  4
//                       [(1  4  5)(2  3)]
//                       [ 1  4  5 (2)(3)]
//                       merge(3, 3, 4)      3  3  4
//                       [ 1  4  5 (2)(3)]
//                       mergeSort(4, 4)     -------
//                       mergeSort(3, 3)     -------
//                       mergeSort(3, 4)     3  3  4
//                       [(1  4)(5) 2  3 ]
//                       merge(0, 1, 2)      0  1  2
//                       [(1  5)(4) 2  3 ]
//                       mergeSort(2, 2)     -------
//                       [(1)(5) 4  2  3 ]
//                       merge(0, 0, 1)      0  0  1
//                       [(5)(1) 4  2  3 ]
//                       mergeSort(1, 1)     -------
//                       mergeSort(0, 0)     -------
//                       mergeSort(0, 1)     0  0  1
//                       mergeSort(0, 2)     0  1  2
//                       mergeSort(0, 4)     0  2  4
//
//                       [ 5  1  4  2  3 ]   l  m  r
