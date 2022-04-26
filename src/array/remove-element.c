#include<stdio.h>
#include"../include/array.h"


// brute force
int removeElement1(int* nums, int numsSize, int val){

   int count = 0;

   for (int i=0;i<numsSize-count;i++){
      if ( nums[i] == val ){
         for (int j=i;j<numsSize-1;j++){
            nums[j] = nums[j+1];
         }
         count++;
         i--;
      }
   }

   return numsSize-count;
}


int removeElement2(int* nums, int numsSize, int val){

   int fast = 0;
   int slow = 0;

   for (fast=0;fast<numsSize;fast++){
      if ( nums[fast] != val ){
         nums[slow++] = nums[fast];
      }
   }

   return slow;
}




int main(){

//                0   1   2   3   4  5  6  7  8   9   10
   int nums[] = {-9, -4, -3, -2, -1, 3, 3, 9, 3, 12, 14};

   int numsSize = sizeof(nums)/sizeof(nums[0]);

   printArray(nums, removeElement2(nums, numsSize, 3));

   return 0;
}
