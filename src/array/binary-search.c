#include<stdio.h>


// loop  invariant: [l,r]
int search1(int *nums, int numsSize, int target){

   int l = 0;
   int r = numsSize-1;

   while( l<=r ){

      int mid = l+((r-l)>>1);

      if      ( target < nums[mid] ) r = mid - 1;
      else if ( nums[mid] < target ) l = mid + 1;
      else                           return mid;

   }

   return -1;
}


// loop  invariant: [l,r) or (l,r]
int search2(int *nums, int numsSize, int target){

   int l = 0;
   int r = numsSize;

   while( l<r ){

      int mid = l+((r-l)>>1);

      if      ( target < nums[mid] ) r = mid;
      else if ( nums[mid] < target ) l = mid + 1;
      else                           return mid;

   }

   return -1;
}




//int search(int *nums, int numsSize, int target){
//
//   int l = 0;
//   int r = numsSize-1;
//
//   int mid = (r + l)/2;
//
//   while( nums[mid] != target ){
//
//      if ( target < nums[mid] ){
//         r = mid-1;
//      }
//      else{
//         l = mid + 1;
//      }
//
//      mid = (r+l)/2;
//
//   }
//
//   return mid;
//}




int main(){
                  0   1   2   3   4  5  6  7  8   9   10
   int nums[] = {-9, -4, -3, -2, -1, 3, 5, 9, 11, 12, 14};

   int numsSize = sizeof(nums)/sizeof(nums[0]);

   for (int i=0;i<numsSize;i++)
   printf("%d\n", search2(nums, numsSize, nums[i]));

   return 0;
}
