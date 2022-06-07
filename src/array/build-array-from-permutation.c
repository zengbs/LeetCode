// TITLE: Build Array from Permutation
// TAG: array
// LEVEL: easy


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int* buildArray(int* nums, int numsSize, int* returnSize)
{
   int *ans = (int*)malloc(numsSize*sizeof(int));

   for (int i=0; i<numsSize; i++){
      ans[i] = nums[nums[i]];
   }

   *returnSize = numsSize;

   return ans;
}

int main (){

   int arr[] = { 0,2,1,5,3,4 };

   int returnSize;

   int *ans = buildArray(arr, sizeof(arr)/sizeof(arr[0]), &returnSize);


   for (int i=0; i<returnSize; i++)
      printf("%d ", ans[i]);

   printf("\n");

   return 0;
}
