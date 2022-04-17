#include <stdio.h>
#include "../include/array.h"


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
//             l     r
// ---------------p--------------------------------------
// 0  3 -1  1  2  4  1  7  8  9  5
//                l  r
// ------------------p-----------------------------------
// 0  3 -1  1  2  1  4  7  8  9  5
//                r  l


int partition(int *arr, int l, int r)
{
   int pivot = arr[(l+r)/2]; // pick pivot point

   while (l <= r){

      // skip the elements that should be on left
      // but stop at the element that should be on right
      while (arr[l] < pivot) l++;

      // skip the elements that should be on right
      // but stop at the element that should be on left
      while (arr[r] > pivot) r--;

      // swap elements, and move left and right indices
      if ( l <= r )  xorSwap(&arr[l++], &arr[r--]);
   }

   return l;
}

void QuickSort(int *arr, int l, int r)
{
   int index = partition(arr, l, r);

   // II Sort l half
   if (l < index - 1) QuickSort(arr, l, index - 1);

   //II Sort r half
   if (index < r)     QuickSort(arr, index, r);
}


int main() {

    int arr[] = {0,3,-1,1,2,4,1,7,8,9,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("original:\n");
    printArray(arr, n);

    QuickSort(arr, 0, n-1);

    printf("sorted:\n");
    printArray(arr, n);
    return 0;
}
