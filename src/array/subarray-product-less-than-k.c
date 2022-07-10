#include <stdio.h>
#include <limits.h>


int numSubarrayProductLessThanK(int* nums, int numsSize, int k)
{

   int left  = 0;
   int right = 0;

   int product;

   while( right < numsSize ){


      while ( product >= k ){

      }

      right++;

   }

}


int main (){

   int arr[] = { 2, 12, 10, 1, 8, 4 };

   int ans = numSubarrayProductLessThanK(arr, sizeof(arr)/sizeof(arr[0]), 20);

   printf("%d\n", ans);

   return 0;
}
