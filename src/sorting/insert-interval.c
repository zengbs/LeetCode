#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

//   x|=|-1  insert

//   x|====|a
//   x|=======|a
//   x|==========|a
//   x|=============|a

//   x|================|b
//   x|====================|b
//   x|=========================|b
//   x|============================|b
//               x              y                     z
//         |--0--|     |----1---|        |------2-----|
//         a           b                 c

//                y|=|a
//                y|===|b
//                y|========|b
//                y|============|b
//                y|===============|b

//                y|=====================|c
//                y|============================|c
//                y|==================================|c
//                y|======================================|c

//          x|=|a
//          x|===|a
//          x|======|a

//          x|=========|b
//          x|==============|b
//          x|==================|b
//          x|=====================|b

#define MAX( x, y ) ( (x) > (y) ) ? (x) : (y)
#define MIN( x, y ) ( (x) < (y) ) ? (x) : (y)

void swap( int *x, int *y ){

   if ( x != y ){
      *x ^= *y;
      *y ^= *x;
      *x ^= *y;
   }

}


int binarySearch( int **intervals, int intervalsSize, int target, bool leftIdx ){

   int l = -1;
   int r = intervalsSize;

   while( l+1 < r ){

      int m = l + (r-l)/2;

      int middleValue = (leftIdx) ? intervals[m][1] : intervals[m][0];

      if      ( middleValue < target ) l = m;
      else if ( middleValue > target ) r = m;
      else                          return m;
   }

   if (leftIdx)  return r;
   else          return l;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize,
             int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes)
{

   int **returnArray = NULL;



   if ( intervalsSize == 0 ){
      *returnSize = 1;
      *returnColumnSizes = (int*)malloc(*returnSize*sizeof(int));
      for (int i=0;i<*returnSize;i++) (*returnColumnSizes)[i] = 2;
      returnArray    = (int**)calloc(1,sizeof(int*));
      returnArray[0] = (int*)calloc(2,sizeof(int));
      returnArray[0][0] = newInterval[0];
      returnArray[0][1] = newInterval[1];
      return returnArray;
   }

// get the index that the starting point of the inseted interval should be at in intervals.
   int left  = binarySearch( intervals, intervalsSize, newInterval[0], true );
   int right = binarySearch( intervals, intervalsSize, newInterval[1], false);


// insert
   if ( left == right+1 ){

//    initialize the returnArray
      *returnSize = intervalsSize+1;
      returnArray = (int**)calloc(*returnSize, sizeof(int*));

      swap( &left, &right );

      for( int i=0;i<*returnSize;i++ ){

         returnArray[i] = (int*)malloc(2*sizeof(int));

         if ( i < left ){
           returnArray[i][0] = intervals[i][0];
           returnArray[i][1] = intervals[i][1];
         }
         else if ( i ==  left ){
           returnArray[i][0] = newInterval[0];
           returnArray[i][1] = newInterval[1];
         }
         else{
           returnArray[i][0] = intervals[i-1][0];
           returnArray[i][1] = intervals[i-1][1];
         }
      }

   }

// merge
   else{

      int leftNonMergedIdx, rightNonMergedIdx;
      int numMergedIntervals;

      // determine the left/right index of merged interval
      leftNonMergedIdx = left-1;
      rightNonMergedIdx = right+1;

      numMergedIntervals = rightNonMergedIdx-leftNonMergedIdx-1;

//    initialize the returnArray
      *returnSize = intervalsSize-numMergedIntervals+1;
      returnArray = (int**)calloc(*returnSize, sizeof(int*));


      newInterval[0] = MIN( newInterval[0], intervals[left ][0] );
      newInterval[1] = MAX( newInterval[1], intervals[right][1] );


      for( int i=0;i<*returnSize;i++ ){

         returnArray[i] = (int*)malloc(2*sizeof(int));

         // copy data from intervals to returnArray before the merged interval
         if      ( i <= leftNonMergedIdx ){
            returnArray[i][0] = intervals[i][0];
            returnArray[i][1] = intervals[i][1];
         }
         // copy data from intervals to returnArray after the merged interval
         else if ( i == leftNonMergedIdx+1 ){
            returnArray[i][0] = newInterval[0];
            returnArray[i][1] = newInterval[1];
         }
         // copy data from newInterval to returnArray
         else{
            returnArray[i][0] = intervals[i+numMergedIntervals-1][0];
            returnArray[i][1] = intervals[i+numMergedIntervals-1][1];
         }
      }
   }

// set returnColumnSizes
   *returnColumnSizes = (int*)malloc(*returnSize*sizeof(int));
   for (int i=0;i<*returnSize;i++) (*returnColumnSizes)[i] = 2;

   return returnArray;

}



int main(){

   // Initialize intervals
   int intervalsColSize = 2;
   int intervalsSize = 4;
   int **intervals = (int**)malloc(intervalsSize*sizeof(int*));

   for (int i=0;i<intervalsSize;i++)
      intervals[i] = (int*)malloc(intervalsColSize*sizeof(int));

   intervals[0][0] = 2;   intervals[0][1] = 3;
   intervals[1][0] = 4;   intervals[1][1] = 5;
   intervals[2][0] = 6;   intervals[2][1] = 7;
   intervals[3][0] = 10;   intervals[3][1] = 1000;

   // Initialize the interval to be inserted
   int newIntervalSize = 1;
   int newInterval[2] = {8 ,11};

   // Insertion
   int returnSize;
   int *returnColumnSizes = NULL;
   int **returnArray = insert( intervals, intervalsSize, &intervalsColSize,
                               newInterval, newIntervalSize, &returnSize, &returnColumnSizes );

   // Print result
   for ( int i=0; i<returnSize; i++){
         printf("%d %d\n", returnArray[i][0], returnArray[i][1]);
   }

   // Free memory
   for (int i=0;i<intervalsSize;i++)  free(intervals[i]);     free(intervals);
   for (int i=0;i<returnSize;i++) free(returnArray[i]);       free(returnArray);
   free(returnColumnSizes);

   return 0;
}
