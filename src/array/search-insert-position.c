// TITLE: Search Insert Position
// TAG: array, binary-search
// LEVEL: easy


#include<stdio.h>
#include<stdlib.h>



int searchInsert(int* nums, int numsSize, int target){

   int l = 0;
   int r = numsSize;

   int m = 0;

   while( l < r ){

      m = l + (r-l)/2;

      if      ( nums[m] < target ) l = m+1;
      else if ( target < nums[m] ) r = m;

      else return m;

   }

   return l;
}

int main(){

   int array[] = {1, 2, 3, 5, 7, 9};

   int numsSize = sizeof(array)/sizeof(array[0]);

   int target = 8;

   int targetIndex = searchInsert( array, numsSize, target );

   printf("%d\n", targetIndex);

   return 0;
}
