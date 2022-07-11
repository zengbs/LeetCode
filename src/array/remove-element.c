#include<stdio.h>
#include"../include/array.h"


void swap( int *a, int *b ){
   if ( a != b ){
      *a ^= *b;
      *b ^= *a;
      *a ^= *b;
   }
}

int removeElement(int* nums, int numsSize, int val){

   int snowBallSize = 0;

   int idx = 0;

   while( idx < numsSize ){

      if ( nums[idx] == val ){
         snowBallSize++;
      }
      else if ( snowBallSize > 0 ){
         swap( &nums[idx], &nums[idx-snowBallSize] );
      }
      idx++;
   }

    return numsSize-snowBallSize;
}



int main(){

//                0   1   2   3   4  5  6  7  8   9  10
   int nums[] = {-9, -4, -3, -2, -1, 3, 3, 9, 3, 12, 14};

   int numsSize = sizeof(nums)/sizeof(nums[0]);

   printArray(nums, removeElement(nums, numsSize, 3));

   return 0;
}
