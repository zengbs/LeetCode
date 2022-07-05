#include<stdio.h>
#include<limits.h>
#include"../include/array.h"


int minSubArrayLen(int target, int* nums, int numsSize){

   int left = 0;
   int right = 0;
   int length;
   int minLength = INT_MAX;
   int sum = 0;

   while( right < numsSize ){

      sum += nums[right];

      while( sum >= target ){

         length = right - left + 1;

         if ( minLength > length ) minLength = length;

         sum -= nums[left++];
      }
      right++;
   }

   return ( minLength == INT_MAX ) ? 0 : minLength;
}


int main(){

   int nums[] = {1,4,4};

   int numsSize = sizeof(nums)/sizeof(nums[0]);

   printf("%d\n", minSubArrayLen(4, nums, numsSize));

   return 0;
}
