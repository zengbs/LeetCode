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

  int lSize = 6;
  int rSize = 6;
  int numsSize = 11;

  int l[6]     = {0,1,6,4,8,7};
  int r[6]     = {4,4,9,7,9,10};
  int nums[11] = {-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10};


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
