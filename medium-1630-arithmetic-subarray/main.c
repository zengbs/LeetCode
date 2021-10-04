#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



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

  printf("[");

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

    bool arithmetic = true;

    for (int j=2; j<r[i]-l[i]+1; j++)
    {
      int diff1 = lr[j] - lr[j-1];

      if (diff1 != diff0) arithmetic &= false;
    }

#   ifdef DEBUG
    for(int i=0; i<lrSize; i++)
    {
      printf("%d ", lr[i]);
    }
#   endif

    if ( arithmetic ) printf("true");
    else              printf("false");

    if (i<rSize-1) printf(",");
  }

  printf("]\n");
}


int main ()
{

  int lSize = 3;
  int rSize = 3;
  int numsSize = 6;

  int l[lSize];
  int r[rSize];
  int nums[numsSize];

  l[0] = 0;
  l[1] = 0;
  l[2] = 2;

  r[0] = 2;
  r[1] = 3;
  r[2] = 5;

  nums[0] = 4;
  nums[1] = 6;
  nums[2] = 5;
  nums[3] = 9;
  nums[4] = 3;
  nums[5] = 7;

  int returnSize;

  bool *boolArry = NULL;

  boolArry = checkArithmeticSubarrays(nums, numsSize, l, lSize, r, rSize, &returnSize);


  //for (int i=0;i<returnSize ; i++)
  //{
  //   if ( boolArry[i] ) printf("true ");
  //   else               printf("false ");
  //}


  return 0;
}
