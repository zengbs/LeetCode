#include <stdio.h>
#include <limits.h>


int maximumDifference(int* nums, int numsSize){

   int left  = 0;
   int right = 0;
   int diff;
   int maxDiff = -1; //

   while( right < numsSize ){

      if ( nums[left] > nums[right] ) left = right;

      diff = nums[right]-nums[left];


      if ( 0 < diff && diff > maxDiff ) maxDiff = diff;

      right++;
   }

   return (maxDiff == -1) ? -1 : maxDiff;

}



int main (){

   int arr[] = { 2, 12, 10, 1, 8, 4 };

   int ans = maximumDifference(arr, sizeof(arr)/sizeof(arr[0]));

   printf("%d\n", ans);

   return 0;
}
