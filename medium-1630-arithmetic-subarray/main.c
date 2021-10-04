#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>



int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize,
                                                        int* r, int rSize, int* returnSize)
{

  *returnSize = rSize;

  int lrSize;

  bool *returnedArry = malloc(sizeof(bool)* (*returnSize));

  int rMax = INT_MIN;
  int lMin = INT_MAX;

  bool arithmetic = false;

  for (int i=0; i<rSize; i++)
  {

      lrSize = r[i] - l[i] + 1;

      int lr[lrSize];

      for (int j=0; j<r[i]-l[i]+1; j++)
      {
        lr[j] = nums[j+l[i]];
      }

      qsort (lr, lrSize, sizeof(int), compare);

      int diff0 = lr[1] - lr[0];

      arithmetic = true;

      for (int j=2; j<r[i]-l[i]+1; j++)
      {
        int diff1 = lr[j] - lr[j-1];

        if (diff1 != diff0) arithmetic &= false;
      }

      returnedArry[i] = arithmetic;
  }

#   ifdef DEBUG
    for(int i=0; i<lrSize; i++)
    {
      printf("%d ", lr[i]);
    }
#   endif


  return returnedArry;
}


int main ()
{

  int lSize = 9;
  int rSize = 9;
  int numsSize = 19;

  int l[9]     = {14,5,11,15,12,13, 9,7,0};
  int r[9]     = {15,8,14,18,15,16,12,8,1};
  int nums[19] = {1,2,10,-6,-7,8,16,0,0,10,20,15,-2,-3,-1,-4,-4,-8,-2};


  int returnSize;

  bool *boolArry = NULL;

  boolArry = checkArithmeticSubarrays(nums, numsSize, l, lSize, r, rSize, &returnSize);

  printf("[");

  for (int i=0;i<returnSize;i++)
  {
    if ( boolArry[i] ) printf("true");
    else              printf("false");

    if (i<rSize-1) printf(",");
  }

  printf("]\n");

  return 0;
}
