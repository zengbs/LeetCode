#include<stdio.h>
#include<limits.h>


int maxSubArray(int* nums, int numsSize){

   int sum = 0;
   int maxSum = INT_MIN;

   for ( int i=0; i<numsSize; i++ ){

      sum += nums[i];

      if ( maxSum < sum ) maxSum = sum;

      if ( sum < 0 ) sum = 0;

   }

   return maxSum;
}

int main(){

   int nums[] = {-2, 1, -3, 4, -1, 2, 1, -7, 4};

   int numsSize = sizeof(nums)/sizeof(nums[0]);

   printf("%d\n", maxSubArray(nums, numsSize));

   return 0;
}
