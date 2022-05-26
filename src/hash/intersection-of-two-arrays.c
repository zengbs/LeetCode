// TITLE: Intersection of Two Arrays
// LEVEL: easy
// TAG: hash, array, linked-list

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node_s{
   int value;
   struct node_s *next;
};

typedef struct node_s node_t;


void addNode( node_t **head, int value ){

   node_t *newNode = (node_t*)malloc(sizeof(node_t));

   newNode->value = value;

   newNode->next = *head;

   *head = newNode;

}

void removeNode( node_t **head, int value ){

   node_t dummy;
   dummy.next = *head;

   node_t *curr = *head;
   node_t *prev = &dummy;

   while( curr != NULL ){

      if ( curr->value == value ){
         prev->next = curr->next;
         free(curr);
         curr = prev->next;
         continue;
      }

      prev = curr;
      curr = curr->next;
   }

   // return head node
   *head = dummy.next;
}

bool searchList( node_t *head, int target ){

   node_t *curr = head;

   while( curr != NULL ){
      if ( curr->value == target ) return true;
      curr = curr->next;
   }

   return false;
}

int* intersection(int* nums1, int nums1Size,
                  int* nums2, int nums2Size, int* returnSize)
{
   size_t hashTableSize = 100;

   node_t **hashTable = (node_t**)calloc(hashTableSize, sizeof(node_t*));

   // add each element in nums1[] to the hash table
   for (int i=0;i<nums1Size;i++){
      if ( !searchList( hashTable[nums1[i]%hashTableSize], nums1[i] ) )
         addNode( &hashTable[nums1[i]%hashTableSize], nums1[i] );
   }

   // check each element of nums2[] exist in the hash table
   *returnSize = 0;
   int *returnArray =  NULL;

   for (int i=0; i<nums2Size; i++){
       if (searchList( hashTable[nums2[i]%hashTableSize], nums2[i] )){
          removeNode( &hashTable[nums2[i]%hashTableSize], nums2[i] );
          (*returnSize)++;
          returnArray = realloc( returnArray, (*returnSize)*sizeof(int) );
          returnArray[(*returnSize)-1] = nums2[i];
      }
   }

   return returnArray;
}



int main(){


   #define nums1Size 4
   #define nums2Size 2

   int nums1[nums1Size] = {1,2,2,1};
   int nums2[nums2Size] = {2,2};
   int returnSize;

   int *result = intersection( nums1, nums1Size, nums2, nums2Size, &returnSize );
   if ( result == NULL ) return 0;

   for (int i=0;i<returnSize;i++)
      printf("%d ", result[i]);

   printf("\n");

   free(result);

   return 0;
}
