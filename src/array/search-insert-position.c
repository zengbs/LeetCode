// TITLE: Search Insert Position
// TAG: array, binary-search
// LEVEL: easy


#include<stdio.h>
#include<stdlib.h>



int searchInsert(int* nums, int numsSize, int target){

   int

}

int main(){

   int array[] = {1, 2, 3, 5, 7, 9};

   int numsSize = sizeof(array)/sizeof(array[0]);

   int target = 8;

   int targetIndex = searchInsert( array, numsSize, target );

   printf("%d\n", targetIndex);

   return 0;
}
