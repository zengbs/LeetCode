// http://alrightchiu.github.io/SecondRound/comparison-sort-merge-sorthe-bing-pai-xu-fa.html
// https://hsm.stackexchange.com/questions/12549/how-did-von-neumann-come-up-with-his-merge-sort-algorithm


/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/array.h"

// merges two subarrays of arr[].
// --> first subarray is arr[l..m]
// --> second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
   int LeftSubArry[m-l+2];
   int RightSubArry[r-m+1];

   // copy arr[l...m] to LeftSubArry[]
   for( int i=0; i<m-l+1; i++ )   LeftSubArry[i] = arr[l+i];

   LeftSubArry[m-l+1] = INT_MAX;

   // copy arr[m+1...r] to RightSubArry[]
   for( int i=0; i<r-m; i++ )     RightSubArry[i] = arr[m+1+i];

   RightSubArry[r-m] = INT_MAX;

   // create two indice for LeftSubArry[] and RightSubArry[]
   int idxLeft = 0;
   int idxRight = 0;

   for( int i=l; i<=r; i++ ){
      if ( LeftSubArry[idxLeft] < RightSubArry[idxRight] )  arr[i] = LeftSubArry[idxLeft++];
      else                                                  arr[i] = RightSubArry[idxRight++];
   }
}


void mergeSort(int arr[], int l, int r)
{
   if (l < r) {

      // same as (l+r)/2, but avoids overflow for large l and h
      int m = l + (r - l) / 2;

      // sort first and second halves
      mergeSort(arr, l, m);
      mergeSort(arr, m + 1, r);
      merge(arr, l, m, r);
   }
}



int main()
{
   int arr[] = { 5, 1, 4, 3, 2 };
   int arr_size = sizeof(arr) / sizeof(arr[0]);

   printf("Given array is \n");
   printArray(arr, arr_size);

   mergeSort(arr, 0, arr_size - 1);

   printf("\nSorted array is \n");
   printArray(arr, arr_size);
   return 0;
}


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
