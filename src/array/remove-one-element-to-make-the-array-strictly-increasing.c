// TITLE: Remove One Element to Make the Array Strictly Increasing
// LEVEL: easy
// TAG: array

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>



bool canBeIncreasing(int* nums, int numsSize){


   int remove = false;

   for (int i=1;i<numsSize;i++){
      if ( nums[i-1] >= nums[i] ){

         if (remove) return false;

         if (i>1 && nums[i-2] >= nums[i]) nums[i] = nums[i-1];

         remove=true;
      }
   }

   return true;


}

// if ( nums[i-1] >= nums[i] ) aims to the case:
//        i
// {1, 2, 0, 3, 4}
// {1, 2, 2, 3, 4}

// if ( .. && nums[i-2] >= nums[i] ) aims to the case:
//             i
// {1, 2, 10,  5, 7}
// {1, 2, 10,  5, 7}

// if ( i>1 && ... ) aims to the case:
// {5, 1, 2, 3}


int main(){

   int array[] = { 1,2,10,5,7};

   int numsSize = sizeof(array)/sizeof(array[0]);

   printf("%d\n", canBeIncreasing(array, numsSize));

   return 0;
}
