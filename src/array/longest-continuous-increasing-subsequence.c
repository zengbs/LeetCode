#include <stdio.h>
#include <limits.h>



int findLengthOfLCIS(int* nums, int numsSize){

   int left  = 0;
   int right = 0;

   int length;
   int maxLength = 1;

   while( right < numsSize-1 ){

      if ( nums[right] >= nums[right+1] ) left = right+1;

      right++;

      length = right-left+1;

      if (maxLength < length) maxLength = length;

   }

   return maxLength;
}


int main (){

   int arr[] = { 2, 12, 10, 1, 8, 4 };

   int ans = findLengthOfLCIS(arr, sizeof(arr)/sizeof(arr[0]));

   printf("%d\n", ans);

   return 0;
}
