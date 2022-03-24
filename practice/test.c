#include <stdio.h>


struct node_s {
   int ary_value;
   int ary_index;
   node_t *next
};

typedef struct node_s node_t;


void insert( node_t **hashTable, int index, int *arry, int arrySize ){

   int t = abs(arry[index]) % arrySize;

   node_t newNode = (node_t*)malloc(sizeof(node_t));

   hashTable[t]->next = newNode;

   newNode->value = arry[index];
   newNode->index = index;
   newNode->next  = hashTable[t]->next;
}


int search( node_t hashTable, int target, int arrySize ){

   int t = abs(target) % arrySize;

   node_t nextNode = hashTable[t]->next;

   while( nextNode != NULL ){

      if ( nextNode->value == target ) return nextNode->index;

      nextNode = nextNode->next;

   }

   return -1;
}


int main(){




   return 0;
}
