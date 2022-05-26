// TITLE: 4Sum II
// LEVEL: medium
// TAGS: hash, array, linked-list

#include <stdio.h>
#include <stdlib.h>


struct node_s {
   struct node_s *next;
   int sum;
   int times;
};

typedef struct node_s node_t;

void addNode( node_t **head, int sum )
{
   node_t *newNode = (node_t*)malloc(sizeof(node_t));

   newNode->sum   = sum  ;
   newNode->times = 1;
   newNode->next  = *head;
   *head = newNode;
}

node_t* search( node_t *head, int targetSum, int *times )
{
   node_t *node = head;
   while( node != NULL ){
      if ( node->sum == targetSum ){
         if (times != NULL) *times = node->times;
         return node;
      }
      node = node->next;
   }

   return NULL;
}



int fourSumCount( int* nums1, int nums1Size, int* nums2, int nums2Size,
                  int* nums3, int nums3Size, int* nums4, int nums4Size )
{

   size_t hashTableSize = 100;

   node_t **hashTable = (node_t**)calloc(hashTableSize, sizeof(node_t*));

   for (int i=0; i<nums1Size; i++){
      for (int j=0; j<nums2Size; j++){

         int sumAB    = nums1[i]+nums2[j];
         int absSumAB = abs(sumAB);

         // note a trap is here!
         // --> why not simply define node_t *head = hashTable[]?
         node_t **head = &hashTable[absSumAB%hashTableSize];
         node_t *node = search(*head, sumAB, NULL);

         if ( node == NULL ){
            addNode( head, sumAB);
         }
         else
            (node->times)++;
      }
   }

   int count = 0;

   for (int i=0; i<nums3Size; i++){
      for (int j=0; j<nums4Size; j++){

         int sumCD    = nums3[i] + nums4[j];
         int absSumCD = abs(sumCD);
         int times=0;

         node_t *head = hashTable[absSumCD%hashTableSize];
         node_t *node = search(head, -sumCD, &times);
         if ( node != NULL )   count += times;
      }
   }

   return count;
}



int main(){

   int nums1[] = { 1, 2};
   int nums2[] = {-2,-1};
   int nums3[] = {-1, 2};
   int nums4[] = { 0, 2};

   int nums1Size = sizeof(nums1)/sizeof(nums1[0]);
   int nums2Size = sizeof(nums2)/sizeof(nums2[0]);
   int nums3Size = sizeof(nums3)/sizeof(nums3[0]);
   int nums4Size = sizeof(nums4)/sizeof(nums4[0]);

   int ans = fourSumCount( nums1, nums1Size, nums2, nums2Size,
                           nums3, nums3Size, nums4, nums4Size );

   printf("%d\n", ans);

   return 0;
}
