#include <stdio.h>
#include <limits.h>


int maximumDifference(int* nums, int numsSize){


   int left = 0;
   int right = 1;

   int maxDiff = 0;

   while( right < numsSize ){

      if ( nums[left] > nums[right]) left = right;

      if ( nums[right]-nums[left] > maxDiff ) maxDiff = nums[right]-nums[left];

      right++;
   }

   return ( maxDiff == 0 ) ?  -1 : maxDiff;

}



int main (){

   int arr[] = { 2, 12, 10, 1, 8, 4 };

   int ans = maximumDifference(arr, sizeof(arr)/sizeof(arr[0]));

   printf("%d\n", ans);

   return 0;
}
