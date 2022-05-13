// TITLE: Binary search
// TAG: array, binary-search
// LEVEL: easy

#include<stdio.h>

int search(int* nums, int numsSize, int target){

   int l = -1;
   int r = numsSize;
   int m;

   while( l+1 != r ){
      m = l + (r-l)/2;
      if ( nums[m] < target ) l = m;
      else                    r = m;
   }

   if ( r < numsSize && nums[r] == target )  return r;
   else                                      return -1;
}



int main(){
//                0   1   2   3   4  5  6  7  8   9   10
   int nums[] = {-9, -4, -3, -2, -1, 3, 5, 9, 11, 12, 14};

   int numsSize = sizeof(nums)/sizeof(nums[0]);

   for (int i=0;i<numsSize;i++)
   printf("%d\n", search(nums, numsSize, nums[i]));

   return 0;
}
