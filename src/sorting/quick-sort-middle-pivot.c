#include <stdio.h>
#include <math.h>
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
//
//                r  l


int partition(int *arr, int l, int r)
{
   //int pivot = arr[(int)(ceil)((float)(l+r)*0.5)]; // pick pivot point
   int pivot = arr[(l+r)/2]; // pick pivot point

   while (l <= r){

      // skip the elements that should be on left
      // but stop at the element that should be on right
      while (arr[l] < pivot) l++;

      // skip the elements that should be on right
      // but stop at the element that should be on left
      while (arr[r] > pivot) r--;

      // is the order of `l++` and `r--` important?

      // swap elements, and move left and right indices
      if ( l <= r )  xorSwap(&arr[l++], &arr[r--]);
   }

   // why return l?
   return l;
}
//------------------
//        p                      l r
//  0 1 2 3 4 5 6      QuickSort(0,6)
//  l           r
//        lr
//      r   l          index = 4
//  -----------------
//    p
//  0 1 2 3 4 5 6      QuickSort(0,3) U
//  l     r
//    lr
//  r   l              index = 2
//  -----------------
//  p
//  0 1 2 3 4 5 6      QuickSort(0,1) U
//  l r
//  lr
//r   l                index = 1      --> return
//  -----------------
//      p
//  0 1 2 3 4 5 6      QuickSort(2,3) L
//      l r
//      lr
//    r   l            index = 3      --> return
//  -----------------
//            p
//  0 1 2 3 4 5 6      QuickSort(4,6) L
//          l   r
//            lr
//          r   l      index = 6      --> return
//  -----------------
//          p
//  0 1 2 3 4 5 6      QuickSort(4,5) U
//          l r
//          lr
//        r   l        index = 5      --> return
//  -----------------

void QuickSort(int *arr, int l, int r)
{
   int index = partition(arr, l, r);
   printf("l=%d, index=%d, r=%d\n", l, index, r);
   // II Sort l half
   if (l < index-1) { printf("l=%d, r=%d\n",  l, index-1);QuickSort(arr, l, index-1);}

   //II Sort r half
   if (index < r)   { printf("l=%d, r=%d\n", index, r); QuickSort(arr, index, r);}
}


int main() {
    int arr[] = {0,1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("original:\n");
    printArray(arr, n);

    QuickSort(arr, 0, n-1);

    printf("sorted:\n");
    printArray(arr, n);
    return 0;
}
