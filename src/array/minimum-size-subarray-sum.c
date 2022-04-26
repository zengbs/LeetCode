// TITLE: Minimum Size Subarray Sum
// TAG: array, sliding window
// LEVEL: medium



#include<stdio.h>
#include<limits.h>
#include"../include/array.h"


int minSubArrayLen(int target, int* nums, int numsSize){

   int l = 0;
   int sum = 0;
   int length = 0;
   int result = INT_MAX;

   for (int r=0;r<numsSize;r++){

      sum += nums[r];

      length = r-l+1;

      while (sum>=target){
         if ( result > length ) result = length;
         sum -= nums[l++];
         length--;
      }
   }

   return result == INT_MAX ? 0 : result;
}


int main(){

   int nums[] = {1,4,4};

   int numsSize = sizeof(nums)/sizeof(nums[0]);

   printf("%d\n", minSubArrayLen(4, nums, numsSize));

   return 0;
}
