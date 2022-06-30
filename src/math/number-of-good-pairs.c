// TITLE: Number of Good Pairs
// LEVEL: easy
// TAG: hash

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define TABLE_SIZE  100

struct node_s{
   struct node_s *next;
   int value;
};

typedef struct node_s node_t;


void addNode( node_t **head, int value )
{
   node_t *new = (node_t*)malloc(sizeof(node_t));

   new->next  = *head;
   new->value = value;

   *head = new;
}


int countTargetInList( node_t *head, int target )
{
   int counter = 0;

   node_t *curr = head;

   while( curr != NULL ){
      if ( curr->value == target ) counter++;
      curr = curr->next;
   }

   return counter;
}


void freeList( node_t *head )
{
   node_t *curr = head;
   node_t *next;

   while( curr != NULL ){
      next = curr->next;
      free(curr);
      curr = next;
   }
}

void freeTable( node_t **hashTable )
{

   for( int i=0; i<TABLE_SIZE; i++ ){
      if ( hashTable[i] != NULL )   freeList( hashTable[i] );
   }

   free(hashTable);
}

int numIdenticalPairs(int* nums, int numsSize)
{

   node_t **hashTable = (node_t**)calloc(TABLE_SIZE, sizeof(node_t*));

   int duplicate;

   int counter = 0;

   for ( int i=0;i<numsSize;i++ ){

      duplicate = countTargetInList( hashTable[abs(nums[i]%TABLE_SIZE)], nums[i] );

      if ( duplicate == 1 ){
         counter++;
      }
      else{
         counter += duplicate;
      }

      addNode( &hashTable[abs(nums[i]%TABLE_SIZE)], nums[i] );
   }

   freeTable( hashTable );

   return counter;
}


int main(){

   int array[] = { 1, 2, 3, 1, 1, 3};

   int ans = numIdenticalPairs( array, sizeof(array)/sizeof(array[0]) );

   printf("%d\n", ans);

}
