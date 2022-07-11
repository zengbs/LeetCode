// Ref: https://leetcode.com/problems/move-zeroes/discuss/172432/THE-EASIEST-but-UNUSUAL-snowball-JAVA-solution-BEATS-100-(O(n))-%2B-clear-explanation

#include <stdio.h>


void swap( int *a, int *b ){

   if ( *a != *b ){
      *a ^= *b;
      *b ^= *a;
      *a ^= *b;
   }
}

void moveZeroes(int* nums, int numsSize){

   int right = 0;

   int snowBallSize = 0;

   while( right < numsSize ){

      if ( nums[right] == 0){
         snowBallSize++;
      }
      else if (snowBallSize > 0){
         swap( &nums[right], &nums[right-snowBallSize] );
      }

      right++;
   }

}

#define SIZE 5

int main(){

   int nums[SIZE] = {0,1,0,3,12};

   moveZeroes( nums, SIZE );

   for (int i=0;i<SIZE;i++) printf("%d ", nums[i]);

   printf("\n");

   return 0;

}
