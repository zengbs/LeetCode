#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct node_s{
   struct node_s *next;
   int value;
   int index;
};

typedef struct node_s node_t;

void addNode( node_t **head, int value, int index )
{
   node_t *node = (node_t*)malloc(sizeof(node_t));

   node->value = value;
   node->index = index;
   node->next  = *head;
   *head = node;
}


bool search( node_t *head, int target, int *index )
{
   node_t *node = head;

   while(node != NULL){
      if (node->value == target){
         *index = node->index;
         return true;
      }
      node = node->next;
   }

   return false;
}


int** twoSum( int* nums, int numsSize, int target, int startIdx, int *returnArraySize )
{
   int hashTableSize = 100;

   node_t **hashTable = (node_t**)calloc(hashTableSize, sizeof(node_t*));
   for ( int i=startIdx; i<numsSize; i++ ){

      node_t **head = &hashTable[abs(nums[i])%hashTableSize];
      addNode( head, nums[i], i );
   }

   int **returnArray = NULL;
   *returnArraySize = 0;
   int targetIdx;


   // we should realloc returnArray as number of correct pairs is not sure
   for ( int i=startIdx; i<numsSize; i++ ){

      // note that a trap is here! abs(target-nums[i]) instead of abs(nums[i])
      node_t *head = hashTable[abs(target-nums[i])%hashTableSize];

      if ( search( head, target-nums[i], &targetIdx ) && targetIdx != i ){
         (*returnArraySize)++;
         returnArray = (int**)realloc( returnArray, (*returnArraySize)*sizeof(int*) );
         returnArray[*returnArraySize-1] = (int*)malloc( 2*sizeof(int) );
         returnArray[*returnArraySize-1][0] = i;
         returnArray[*returnArraySize-1][1] = targetIdx;
      }
   }

   return returnArray;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{

   int **returnArray = NULL;
        *returnSize = 0;

   for (int i=0; i<numsSize; i++){

      int returnTwoSumSize;

      int **returnTwoSum = twoSum(nums, numsSize, -nums[i], i+1, &returnTwoSumSize);

      if( returnTwoSum != NULL ){
         for (int k=0; k<returnTwoSumSize; k++){
            (*returnSize)++;
            returnArray = (int**)realloc(returnArray, (*returnSize)*sizeof(int*));
            returnArray[*returnSize-1] = (int*)malloc( 3*sizeof(int) );

            returnArray[*returnSize-1][0] = nums[i];
            returnArray[*returnSize-1][1] = nums[returnTwoSum[k][0]];
            returnArray[*returnSize-1][2] = nums[returnTwoSum[k][1]];
         }
      }
   }



   *returnColumnSizes = (int*)malloc(*returnSize*sizeof(int));

   for (int i=0; i<*returnSize; i++)  (*returnColumnSizes)[i] = 3;


   return returnArray;
}


int main()
{

   int arry[] = {0,-1,1,-2,2};

   int arrySize = sizeof(arry)/sizeof(arry[0]);

   int target = 0;

   int **returnArray = NULL;
   int returnSize;
   int *returnColumnSizes = NULL;

   returnArray = threeSum( arry,  arrySize, &returnSize, &returnColumnSizes );

   if ( returnArray == NULL ) return 0;

   for (int i=0; i<returnSize; i++){
      for (int j=0; j<returnColumnSizes[i]; j++){
         printf("%d ", returnArray[i][j]);
      }
      printf("\n");
   }

   return 0;
}
