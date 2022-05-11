#include <stdio.h>
#include <math.h>
#include "../include/array.h"

#define DEBUG

void xorSwap( int *a, int *b ){
   if ( *a != *b ){
      *a ^= *b;
      *b ^= *a;
      *a ^= *b;
   }
}


// ---------------p--------------------------------------
// 0  3  5  7  1  4  2  1  8  9 -1
// l                             r
// ---------------p--------------------------------------
// 0  3  5  7  1  4  2  1  8  9 -1
//       l                       r
// ---------------p--------------------------------------
// 0  3 -1  7  1  4  2  1  8  9  5
//       l                       r
// ---------------p--------------------------------------
// 0  3 -1  7  1  4  2  1  8  9  5
//          l           r
// ---------------p--------------------------------------
// 0  3 -1  1  1  4  2  7  8  9  5
//          l           r
// ---------------p--------------------------------------
// 0  3 -1  1  1  4  2  7  8  9  5
//                l  r
// ---------------p--------------------------------------
// 0  3 -1  1  1  2  4  7  8  9  5
//                l  r
// ---------------p--------------------------------------
// 0  3 -1  1  1  2  4  7  8  9  5
//                r  l

//-------p----------
// 0  3 -1  1  1  2
// l              r
// l     r
//-------p----------
//-1  3  0  1  1  2
//    lr
//-------p----------
//-1  3  0  1  1  2
// r  l

int partition(int *arr, int l, int r)
{
   int arrSize = r-l+1;
   int pivot;

   pivot = arr[(l+r)/2]; // pick pivot point
   int pivotIdx = (l+r)/2;

   while (l <= r){

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

   // why return l? why don't return pivot+1 or r?
   return l;
}


void QuickSort(int *arr, int l, int r)
{
   int idx = partition(arr, l, r);

   // step-1: sort left half
   // set the previous pivot as the right index
   if (l < idx-1) QuickSort(arr, l, idx-1);

   //step-2: sort right half
   // set the elment on the right of pivot as the left index
   if (idx < r)   QuickSort(arr, idx, r);

   // is the order of `step-1` and `step-2` important? no
}


int main() {
    int arr[] = {10, 3, 5, 7, 1, 4, 2, 1, 8, 9, -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("original:\n");
    printArray(arr, n);

    QuickSort(arr, 0, n-1);

    printf("sorted:\n");
    printArray(arr, n);
    return 0;
}
