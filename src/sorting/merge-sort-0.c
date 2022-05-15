// http://alrightchiu.github.io/SecondRound/comparison-sort-merge-sorthe-bing-pai-xu-fa.html
// https://hsm.stackexchange.com/questions/12549/how-did-von-neumann-come-up-with-his-merge-sort-algorithm

#include<limits.h>

// merge two subarrays arr[l..m] and arr[m+1..r] into arr[l..r]
void merge(int arr[], int l, int m, int r)
{
   int left[m-l+2];  // m-(l-1)+1
   int right[r-m+1]; // r-m+1

   // copy arr[l...m] to left[0..m-l]
   for( int i=0; i<m-l+1; i++ )   left[i] = arr[l+i];


   // copy arr[m+1...r] to right[0..r-m-1]
   for( int i=0; i<r-m; i++ )     right[i] = arr[m+1+i];


   // append INT_MAX/INT_MIN to left[] and right[] if the result is in ascending/descending order
   left[m-l+1] = INT_MAX; right[r-m] = INT_MAX;


   // create two indice for left[] and right[]
   int subl = 0;
   int subr = 0;

   // if ( left[subl] > right[subr] ): descending order
   // if ( left[subl] < right[subr] ):  ascending order
   for( int i=l; i<=r; i++ ){
      if ( left[subl] < right[subr] )  arr[i] = left[subl++];
      else                             arr[i] = right[subr++];
   }
}


// usage: mergeSort(array, 0, arrSize-1);
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
