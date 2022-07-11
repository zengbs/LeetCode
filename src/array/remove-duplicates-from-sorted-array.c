
int removeDuplicates(int* nums, int numsSize){

   int counter = 0;

   for( int i=1; i<numsSize; i++ ){
      if ( nums[i] == nums[i-1] ) counter++;
      else nums[i-counter] = nums[i];
   }

   return numsSize-counter;
}
