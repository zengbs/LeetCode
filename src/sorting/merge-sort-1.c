// https://youtu.be/KAgkvtKMbwY

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/array.h"

// merges two subarrays arr[l..m-1] and arr[m..r-1] into arr[l..r-1].
void merge(int arr[], int l, int m, int r)
{
   int left[m-l+1];  // (m-1)-(l-1)+1
   int right[r-m+1]; // (r-1)-(m-1)+1

   // copy data to left subarray
   for(int i=l;i<m;i++) left[i-l] = arr[i];

   // copy data to right subarray
   for(int i=m;i<r;i++) right[i-m] = arr[i];

   // append INT_MAX to left and right subarrays (why?)
   left[m-l] = INT_MAX; right[r-m] = INT_MAX;

   int sl = 0;
   int sr = 0;

   // merge two subarrays in ascending order
   for ( int k=l;k<r;k++ ){
      if ( left[sl] > right[sr] )   arr[k] = right[sr++];
      else                          arr[k] =  left[sl++];
   }
}


// arr[l,...,r-1]
void mergeSort(int arr[], int l, int r)
{
   // base case
   if ( r-1 <= l ) return;

   // prevent overflow
   int m = l + (r-l)/2;

   // split into left subarray
   mergeSort(arr, l, m);

   // split into right subarray
   mergeSort(arr, m, r);

   // merge subsrrays
   merge( arr, l, m, r );
}




int main()
{
   int arr[] = { 5, 1, 4, 3, 2 };
   int arr_size = sizeof(arr) / sizeof(arr[0]);

   printf("Given array is \n");
   printArray(arr, arr_size);

   mergeSort(arr, 0, arr_size);

   printf("\nSorted array is \n");
   printArray(arr, arr_size);
   return 0;
}
