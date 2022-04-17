// https://hackmd.io/@zengbs/HyZA4bYN5

#include <iostream>
#include "../include/array.h"

void xorSwap( int *a, int *b ){
   if ( *a != *b ){
      *a ^= *b;
      *b ^= *a;
      *a ^= *b;
   }
}

// -----------------
//  i  j
//     1  7  2  5
// -----------------
//    ij
//     1  7  2  5
// -----------------
//     i  j
//     1  7  2  5
// -----------------
//     i     j
//     1  7  2  5
// -----------------
//        i  j
//     1  7  2  5
// -----------------
//        i     j
//     1  2  7  5
// -----------------
//           i  j
//     1  2  5  7
// -----------------

int Partition(int *arr, int l, int r){

   int pivot = arr[r];
   int i = l-1;

   for ( int j=l; j<r; j++ ){
      if ( arr[j] < pivot )   xorSwap(&arr[++i], &arr[j]);
   }

   xorSwap(&arr[++i], &arr[r]);

   return i;
}

void QuickSort(int *arr, int l, int r){
    if (l < r) {
        int pivot = Partition(arr, l, r);
        QuickSort(arr, l, pivot - 1);
        QuickSort(arr, pivot + 1, r);
    }
}


int main() {

    int arr[] = {1,7,2,5, 9, 3, 10,-1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << "original:\n";
    printArray(arr, n);

    QuickSort(arr, 0, n-1);

    std::cout << "sorted:\n";
    printArray(arr, n);
    return 0;
}
