// TITLE: Maximum Subarray
// LEVEL: easy
// TAG: array, greedy, dynamic-programming

#include<stdio.h>
#include<limits.h>


int maxSubArray(int* nums, int numsSize){

   int count = 0;
   int result = INT_MIN;

   for ( int i=0; i<numsSize; i++ ){

      count += nums[i];

      if ( result < count ) result = count;

      if ( count < 0 ) count = 0;

   }

   return result;
}

int main(){

   int nums[] = {-2, 1, -3, 4, -1, 2, 1, -7, 4};

   int numsSize = sizeof(nums)/sizeof(nums[0]);

   printf("%d\n", maxSubArray(nums, numsSize));

   return 0;
}
