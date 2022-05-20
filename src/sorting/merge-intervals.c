// TITLE: merge intervals
// LEVEL: medium
// TAG: sorting, merge, interval

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX( x, y ) ( (x) > (y) ) ? (x) : (y)
#define MIN( x, y ) ( (x) < (y) ) ? (x) : (y)


// merge arr[l..m] and arr[m+1..r]
void mergeStartingTime( int **arr, int l, int m, int r ){

   int left[m-l+2][2]; // m-(l-1)+1
   int right[r-m+1][2]; // r-m+1

   for ( int i=l  ;i<m+1;i++ ) {
      left   [i-l][0] = arr[i][0];
      left   [i-l][1] = arr[i][1];
   }
   for ( int i=m+1;i<r+1;i++ ) {
      right[i-m-1][0] = arr[i][0];
      right[i-m-1][1] = arr[i][1];
   }

   left [m-l+1][0] = INT_MAX;
   right  [r-m][0] = INT_MAX;

   int subl = 0;
   int subr = 0;

   for ( int i=0;i<r-l+1;i++ ){
      if ( left[subl][0] < right[subr][0] ) {
         arr[i+l][0] = left [subl][0];
         arr[i+l][1] = left [subl++][1];
      }
      else{
         arr[i+l][0] = right[subr][0];
         arr[i+l][1] = right[subr++][1];
      }
   }
}


// divide arr[l..r] into arr[l..m] and arr[m+1..r]
void mergeSort( int **arr, int l, int r ){

   // base case
   if ( r <= l ) return;

   int m = l + (r-l)/2;

   mergeSort( arr, l  , m );
   mergeSort( arr, m+1, r );

   mergeStartingTime( arr, l, m, r );
}



int** merge(int** intervals, int  intervalsSize,  int*  intervalsColSize,
                             int* returnSize,     int** returnColumnSizes)
{

// sort the start points within intervals
   mergeSort( intervals, 0, intervalsSize-1 );

   *returnSize = 1;

   int **returnArray = (int**)calloc(intervalsSize, sizeof(int*));

// add the first interval to returnArray array
   returnArray[0] = (int*)malloc(2*sizeof(int));
   returnArray[0][0] = intervals[0][0];
   returnArray[0][1] = intervals[0][1];


   for ( int i=1;i<intervalsSize;i++ ){

      // merge intervals
      if ( returnArray[(*returnSize)-1][1] >= intervals[i][0] ){
         returnArray[(*returnSize)-1][1] = MAX(returnArray[(*returnSize)-1][1], intervals[i][1]);
      }

      // add interval
      else{
         returnArray[(*returnSize)++] = (int*)malloc(2*sizeof(int));
         returnArray[(*returnSize)-1][0] = intervals[i][0];
         returnArray[(*returnSize)-1][1] = intervals[i][1];
      }
   }


// get returnColumnSizes
   *returnColumnSizes = (int*)malloc(*returnSize*sizeof(int));
   for (int i=0;i<*returnSize;i++) (*returnColumnSizes)[i] = 2;


   return returnArray;
}


int main(){


   int **intervals = NULL;
   int intervalsSize = 5;
   int intervalsColSize = 2;
   int returnSize = 1;
   int *returnColumnSizes = NULL;


   intervals = (int**)malloc(intervalsSize*sizeof(int*));

   for (int i=0;i<intervalsSize;i++)
      intervals[i] = (int*)malloc(intervalsColSize*sizeof(int));

   intervals[0][0] = 2;   intervals[0][1] = 3;
   intervals[1][0] = 4;   intervals[1][1] = 5;
   intervals[2][0] = 6;   intervals[2][1] = 7;
   intervals[3][0] = 8;   intervals[3][1] = 9;
   intervals[4][0] = 1;   intervals[4][1] = 10;

   int **returnArray = merge( intervals, intervalsSize, &intervalsColSize, &returnSize, &returnColumnSizes );

   for ( int i=0; i<returnSize; i++){
         printf("%d %d\n", returnArray[i][0], returnArray[i][1]);
   }

   for (int i=0;i<intervalsSize;i++)  free(intervals[i]);     free(intervals);
   for (int i=0;i<returnSize;i++) free(returnArray[i]);       free(returnArray);
   free(returnColumnSizes);

}
