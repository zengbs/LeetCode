#include <limits.h>

// merge arr[l..m-1] and arr[m..r] into arr[l..r]
void merge(int *arr, int l, int m, int r){

   // arr[l..m-1]
   int left[m-l+1]; // (m-1)-(l-1)+1

   // arr[m..r]
   int right[r-m+2]; // r-(m-1)+1

   // copy arr[l..m-1] to left[]
   for (int i=l;i<m;i++) left[i-l] = arr[i];

   // copy arr[m..r] to right[]
   for (int i=m;i<r+1;i++) right[i-m] = arr[i];

   // append INT_MAX/INT_MIN to left[] and right[] if the result is in ascending/descending order
   left[m-l] = INT_MAX; right[r-m+1] = INT_MAX;

   int subl = 0;
   int subr = 0;

   // if ( left[subl] > right[subr] ): descending order
   // if ( left[subl] < right[subr] ):  ascending order
   for ( int k=l; k<r+1; k++ ){
      if ( left[subl] > right[subr] )   arr[k] = right[subr++];
      else                              arr[k] = left[subl++];
   }

}



// usage: mergeSort(array, 0, arrSize-1);
// split arr[l..r] into arr[l..m-1] and arr[m..r]
void mergeSort(int *arr, int l, int r){

   if ( r <= l ) return;


   // round m upward
   int m = l + (r-l)/2 + 1;

   mergeSort( arr, l, m-1 );
   mergeSort( arr, m,   r );

   merge(arr, l, m, r);

}
