#include<stdio.h>
#include<limits.h>
#include<stdint.h>


int thirdMax(int* nums, int numsSize){

   long     firstMax  = (long)INT32_MIN-1;
   long    secondMax  = (long)INT32_MIN-1;
   long     thirdMax  = (long)INT32_MIN-1;

   for ( int i=0;i<numsSize;i++ ){

      if ( firstMax < nums[i] ){
         thirdMax = secondMax;
         secondMax = firstMax;
         firstMax = nums[i];
      }

      else if ( secondMax < nums[i] && nums[i] < firstMax ){
         thirdMax  = secondMax;
         secondMax = nums[i];
      }

      else if ( thirdMax < nums[i] && nums[i] < secondMax ){
         thirdMax = nums[i];
      }

   }

   if (thirdMax == (long)INT32_MIN-1) return firstMax;
   else                               return thirdMax;
}


int main(){

   int array[] = {2,2,3,1};

   int numsSize = sizeof(array)/sizeof(array[0]);


   printf("%d\n", thirdMax( array, numsSize ));

   return 0;
}
