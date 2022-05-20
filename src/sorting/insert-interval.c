// TITLE: insert interval
// LEVEL: medium
// TAG: sorting, merge-intervals

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

//=============================================================================================
//  Description : find the position of a target value within a sorted array
//
//  Input       : intervals     : the original intervals[i][2] given by problem
//                                --> intervals[i][0] and intervals[i][1] stores the start and
//                                    the end, respectively, of the i-th intervals
//                                     --> i ranges from 0 to intervalsSize-1
//                intervalsSize : the number of intervals in intervals[i][2]
//                target        : the target you interested in
//                startIdx      : (false/true)-->find the position of the start/end point of
//                                the inserted interval
//
//  Output      : target is     in the sorted array : return the position of the target
//                target is not in the sorted array : if startIdx == (true/false)
//                --> return the nearest position to the (right/left) of target
//==============================================================================================
int binarySearch( int **intervals, int intervalsSize, int target, bool startIdx ){

   int l = -1;
   int r = intervalsSize;

   while( l+1 < r ){

      int m = l + (r-l)/2;

      int middleValue = (startIdx) ? intervals[m][1] : intervals[m][0];

      if      ( middleValue < target ) l = m;
      else if ( middleValue > target ) r = m;
      else                          return m;
   }

   if (startIdx)  return r;
   else           return l;
}


//=============================================================================================
// Description : append interval [start, end] to the array at idx
//=============================================================================================
void addInterval( int **array, int idx, int start, int end ){

   array[idx] = (int*)malloc(2*sizeof(int));
   array[idx][0] = start;
   array[idx][1] = end;

}


//=============================================================================================
// Description : insert an interval into the original intervals given by problem
//
// Input       : intervals         : the original intervals[i][2] given by problem
//                                   --> intervals[i][0] and intervals[i][1] stores the start and
//                                       the end, respectively, of the i-th intervals
//                                        --> i ranges from 0 to intervalsSize-1
//               intervalsSize     : the number of intervals in intervals[i][2]
//               intervalsColSize  : an 1-D array storing the size of each interval within intervals
//               newInterval       : the new interval to be inserted
//               newIntervalSize   : the number of intervals within the newInterval
//               returnSize        : the unmber of intervals within an returned array (answer)
//               returnColumnSizes : an 1-D array storing the size of each interval within returned array
//
// Output      : an returned 2D array storing the inserted/merged interval
//=============================================================================================

int** insert(int** intervals, int intervalsSize, int* intervalsColSize,
             int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes)
{

   int **returnArray = NULL;

// handle the case that intervalsSize is zero
   if ( intervalsSize == 0 ){

      *returnSize = 1;
      *returnColumnSizes = (int*)malloc(*returnSize*sizeof(int));

      for (int i=0;i<*returnSize;i++) (*returnColumnSizes)[i] = 2;

      returnArray    = (int**)calloc(1,sizeof(int*));

      addInterval( returnArray, 0, newInterval[0], newInterval[1] );

      return returnArray;
   }

// get the position of start/end of the newInterval
   int left  = binarySearch( intervals, intervalsSize, newInterval[0], true );
   int right = binarySearch( intervals, intervalsSize, newInterval[1], false);


// perform insertion
   if ( left == right+1 ){

//    initialize the returnArray
      *returnSize = intervalsSize+1;
      returnArray = (int**)calloc(*returnSize, sizeof(int*));

      swap( &left, &right );

      for( int i=0; i<*returnSize; i++ ){

         returnArray[i] = (int*)malloc(2*sizeof(int));

//       copy the left part of the intervals to returnArray
         if ( i < left +1 ){
           addInterval( returnArray, i, intervals[i][0], intervals[i][1] );
         }
//       insert newInterval into returnArray
         else if ( i ==  left+1 ){
           addInterval( returnArray, i,   newInterval[0],  newInterval[1] );
         }
//       copy the right part of the intervals to returnArray
         else{
           addInterval( returnArray, i, intervals[i-1][0], intervals[i-1][1] );
         }
      }

   }

// merge intervals
   else{

      int maxIdxLeftUnperturbedBin, minIdxRightUnperturbedBin, numPerturbedBins;

//    the maximum index of the unperturbed bins on the left perturbed region
      maxIdxLeftUnperturbedBin  = left-1;

//    the minimum index of the unperturbed bins on the right perturbed region
      minIdxRightUnperturbedBin = right+1;

//    the number of unperturbed intervals
      numPerturbedBins = minIdxRightUnperturbedBin-maxIdxLeftUnperturbedBin-1;

//    initialize the returnArray
      *returnSize = intervalsSize-numPerturbedBins+1;
      returnArray = (int**)calloc(*returnSize, sizeof(int*));

//    the start/end of the merged bin
      newInterval[0] = MIN( newInterval[0], intervals[left ][0] );
      newInterval[1] = MAX( newInterval[1], intervals[right][1] );


      for( int i=0;i<*returnSize;i++ ){

//       copy the left part of the intervals to returnArray
         if      ( i <= maxIdxLeftUnperturbedBin ){
            addInterval( returnArray, i, intervals[i][0], intervals[i][1] );
         }
//       copy the merged bin to returnArray
         else if ( i == maxIdxLeftUnperturbedBin+1 ){
            addInterval( returnArray, i, newInterval[0], newInterval[1] );
         }
//       copy the right part of the intervals to returnArray
         else{
            addInterval( returnArray, i, intervals[i+numPerturbedBins-1][0],
                                         intervals[i+numPerturbedBins-1][1] );
         }
      }
   }

// set returnColumnSizes
   *returnColumnSizes = (int*)malloc(*returnSize*sizeof(int));
   for (int i=0;i<*returnSize;i++) (*returnColumnSizes)[i] = 2;

   return returnArray;
}



int main(){

   // initialize intervals
   int intervalsColSize = 2;
   int intervalsSize = 4;
   int **intervals = (int**)malloc(intervalsSize*sizeof(int*));

   for (int i=0;i<intervalsSize;i++)
      intervals[i] = (int*)malloc(intervalsColSize*sizeof(int));

   intervals[0][0] = 2;   intervals[0][1] = 3;
   intervals[1][0] = 4;   intervals[1][1] = 5;
   intervals[2][0] = 6;   intervals[2][1] = 7;
   intervals[3][0] = 10;   intervals[3][1] = 1000;

   // initialize the interval to be inserted
   int newIntervalSize = 1;
   int newInterval[2] = {8 ,11};

   // insertion
   int returnSize;
   int *returnColumnSizes = NULL;
   int **returnArray = insert( intervals, intervalsSize, &intervalsColSize,
                               newInterval, newIntervalSize, &returnSize, &returnColumnSizes );

   // print result
   for ( int i=0; i<returnSize; i++){
         printf("%d %d\n", returnArray[i][0], returnArray[i][1]);
   }

   // free memory
   for (int i=0;i<intervalsSize;i++)  free(intervals[i]);     free(intervals);
   for (int i=0;i<returnSize;i++) free(returnArray[i]);       free(returnArray);
   free(returnColumnSizes);

   return 0;
}
