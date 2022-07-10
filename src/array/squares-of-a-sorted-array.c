
int* sortedSquares(int* nums, int numsSize, int* returnSize){

   *returnSize = numsSize;

   int *returnArray = (int*) malloc(*returnSize*sizeof(int));

   int l = 0;
   int r = numsSize-1;
   int k = numsSize-1;

   while(l <= r){
      if ( abs(nums[l]) < abs(nums[r]) ){
         returnArray[k--] = nums[r]*nums[r];
         r--;
      }
      else{
         returnArray[k--] = nums[l]*nums[l];
         l++;
      }
   }
   return returnArray;
}
