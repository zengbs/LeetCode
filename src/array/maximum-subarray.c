#include<stdio.h>
#include<limits.h>

int maxSubArray(int* nums, int numsSize){

   int right = 0;

   int sum = 0;
   int maxSum = INT_MIN;

   while( right < numsSize ){

      if ( sum < 0 ) sum = 0;

      sum += nums[right++];

      if ( maxSum < sum ) maxSum = sum;
   }

   return maxSum;

}


int main(){

   int nums[] = {-2, 1, -3, 4, -1, 2, 1, -7, 4};

   int numsSize = sizeof(nums)/sizeof(nums[0]);

   printf("%d\n", maxSubArray(nums, numsSize));

   return 0;
}
