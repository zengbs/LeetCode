// TITLE: two sum
// LEVEL: easy
// TAG: array, hash, linked-list

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>



struct node_s{
   int value;
   int index;
   struct node_s *next;
};

typedef struct node_s node_t;


void addNode( node_t **head, int value, int index ){

   node_t *newNode = (node_t*)malloc(sizeof(node_t));

   newNode->value = value;
   newNode->index = index;
   newNode->next = *head;

   *head = newNode;
}


bool search( node_t *head, int target, node_t **targetNode ){

   node_t *node = head;

   while(node != NULL){

      if (node->value == target) {

         *targetNode = node;

         return true;
      }

      node = node->next;
   }

   return false;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){

   *returnSize = 2;
   int hashTableSize = 100;

   int *indice = (int*)malloc(sizeof(int)*(*returnSize));
   node_t **hashTable = (node_t**)calloc(hashTableSize, sizeof(node_t*));

   for ( int i=0;i<numsSize; i++ ){

      int hashedTargetIdx = abs((target-nums[i])%hashTableSize);

      node_t *targetNode; // Why we cannot use `node_t targetNode`?

      if ( search( hashTable[hashedTargetIdx], target-nums[i], &targetNode ) ){
         indice[0] = targetNode->index;
         indice[1] = i;
         return indice;
      }

      int hashedIdx = abs(nums[i]%hashTableSize);
      addNode(&hashTable[hashedIdx], nums[i], i);
   }

   return NULL;
}



int main(){

   int arry[] = {2, 5, -1, 0, -3};

   int target = 5;

   int returnSize;

   int *indice = twoSum( arry, sizeof(arry)/sizeof(arry[0]), target, &returnSize );
   if ( indice == NULL ) { printf("indice == NULL!\n"); exit(0); }

   for ( int i=0;i<returnSize;i++ ){
      printf("%d ", indice[i]);
   }

   printf("\n");

   return 0;
}
