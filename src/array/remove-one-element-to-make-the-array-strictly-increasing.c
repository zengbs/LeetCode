// TITLE: Remove One Element to Make the Array Strictly Increasing
// LEVEL: easy
// TAG: array

// Ref: https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/discuss/1387010/JAVA-EASY-TO-UNDERSTAND-SOLUTION-well-explained-with-pictureoror-100-FASTER

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>



bool canBeIncreasing(int* nums, int numsSize)
{

   int peakCounter = 0;
   int peakIdx = 0;


   for ( int i=0; i<numsSize-1; i++ ){
      if ( nums[i] >= nums[i+1] ){
         peakCounter++;
         peakIdx = i;
      }
   }


   // if peakCounter > 1
   if ( peakCounter > 1 ) return false;


   // if peakCounter == 1
   if ( peakCounter == 1 ){
      if ( peakIdx == 0 || peakIdx == numsSize-2 )                                return true;
      if ( nums[peakIdx+2] > nums[peakIdx] || nums[peakIdx+1] > nums[peakIdx-1] ) return true;
      else return false;
   }

   // if peakCounter == 0
   return true;

}


int main(){

   int array[] = { 1,2,10,5,7};

   int numsSize = sizeof(array)/sizeof(array[0]);

   printf("%d\n", canBeIncreasing(array, numsSize));

   return 0;
}
