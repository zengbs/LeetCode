#include <stdio.h>


void swap( int *a, int *b ){

   if ( *a != *b ){
      *a ^= *b;
      *b ^= *a;
      *a ^= *b;
   }
}

void moveZeroes(int* nums, int numsSize){

   if (numsSize == 1) return;

   int x = 0;
   int y = 0;

   while(y < numsSize){
      if ( nums[y] == 0 ) { y++; }
      else {swap( &nums[x], &nums[y] ); y++; x++; }
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
