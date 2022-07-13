#include<stdio.h>
#include<limits.h>
#include"../include/array.h"


#define MIN( x, y ) ( ( (x) < (y) ) ? (x) : (y) )


int maxArea(int* height, int heightSize){

   int left = 0;
   int right = heightSize-1;

   int volume;
   int maxVolume = 0;

   while( left < right ){

      volume = ( right - left )*MIN( height[right], height[left] );

      if ( maxVolume < volume ) maxVolume = volume;

      if      ( height[left]  >  height[right] )     right--;
      else if ( height[right] >  height[left] )      left++;
      else { left++; right--; }
   }

   return maxVolume;
}


int main(){

   int nums[] = {1,8,6,2,5,4,8,3,7};

   int numsSize = sizeof(nums)/sizeof(nums[0]);

   printf("%d\n", maxArea(nums, numsSize));

   return 0;
}
