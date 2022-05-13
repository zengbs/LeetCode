#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "../include/array.h"

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

   // append INT_MAX to left[] and right[]
   left[m-l] = INT_MAX; right[r-m+1] = INT_MAX;

   int subl = 0;
   int subr = 0;

   // merge left[] and right[] into arr[l..r] in ascending order
   for ( int k=l; k<r+1; k++ ){
      if ( left[subl] > right[subr] )   arr[k] = right[subr++];
      else                              arr[k] = left[subl++];
   }

}



// split arr[l..r] into arr[l..m-1] and arr[m..r]
void mergeSort(int *arr, int l, int r){

   if ( r <= l ) return;


   // round m upward
   int m = l + (r-l)/2 + 1;

   mergeSort( arr, l, m-1 );
   mergeSort( arr, m,   r );

   merge(arr, l, m, r);

}


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{


  int arrSize = 3000;

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
