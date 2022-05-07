#include<stdio.h>
#include<stdlib.h>
#include "../include/tools.h"

# define HASH_TABLE_SIZE 100



struct node_s{
   int value;
   struct node_s *next;
};


typedef struct node_s node_t;


void addNode(node_t **head, int value){

   node_t *newHead = (node_t*)malloc(sizeof(node_t));

   newHead->value = value;

   newHead->next = *head;

   *head = newHead;
}

bool search( node_t *head, int target ){

   node_t *node = head;

   while( node != NULL ){

      if (node->value == target) return true;

      node = node->next;
   }

   return false;
}



bool checkIfExist(int *arr, int arrSize) {


   node_t  **hashTable = (node_t**)calloc(HASH_TABLE_SIZE, sizeof(*hashTable));

   int hashedValue1, hashedValue2;

   int numZero = 0;

   for ( int i=0;i<arrSize;i++ ){

      if ( arr[i] == 0 ) {

         numZero++;

         if ( numZero == 2 )   return true;
         else                  continue;
      }

      // arr[i] is even
      if ( (arr[i]&1) == 0 ){
         hashedValue1 = abs((arr[i]/2)%HASH_TABLE_SIZE);
         hashedValue2 = abs((arr[i]*2)%HASH_TABLE_SIZE);

         // check if arr[i]/2 exist
         // collision
         if ( hashTable[hashedValue1] != NULL ){
            if ( search( hashTable[hashedValue1], arr[i]/2 ) ) return true;
            else addNode( &hashTable[abs(arr[i]%HASH_TABLE_SIZE)], arr[i] );
         }
         // no collision
         else{
            addNode( &hashTable[abs(arr[i]%HASH_TABLE_SIZE)], arr[i] );
         }

         // check if arr[i]*2 exist
         // collision
         if ( hashTable[hashedValue2] != NULL ){
            if ( search( hashTable[hashedValue2], arr[i]*2 ) ) return true;
            else addNode( &hashTable[abs(arr[i]%HASH_TABLE_SIZE)], arr[i] );
         }
         // no collision
         else{
            addNode( &hashTable[abs(arr[i]%HASH_TABLE_SIZE)], arr[i] );
         }
      }

      // arr[i] is odd
      else{

         hashedValue2 = abs((arr[i]*2)%HASH_TABLE_SIZE);

         // check if arr[i]*2 exist
         if ( hashTable[hashedValue2] != NULL ){ // collision
            if ( search( hashTable[hashedValue2], arr[i]*2 ) ) return true;
            else addNode( &hashTable[abs(arr[i]%HASH_TABLE_SIZE)], arr[i] );
         }
         else{ // no collision
            addNode( &hashTable[abs(arr[i]%HASH_TABLE_SIZE)], arr[i] );
         }
      }
   }

   return false;
}


int main(){

   int array[] = {-2,0,0};

   printf("%d\n", checkIfExist(array, sizeof(array)/sizeof(array[0])));

   return 0;
}
