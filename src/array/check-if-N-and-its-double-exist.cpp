#include<stdio.h>

struct node_s{
   int value;
   nosd_t *next;
};


typedef struct node_s node_t;


void addNode(node_t **head, int value){

   node_t *newHead = (node_t*)malloc(sizeof(node_t));

   newHead->value = value;

   newHead->next = head;

   *head = newHead;
}

bool search( node_t *head, int target ){

   node_t node;

   while( node.next != NULL ){

      if (node.value == target) return true;

      node = node.next;

   }

   return false;
}

int hash(int input, int hashTableSize){

   return output = intput % hashTableSize;
}

bool checkIfExist(int *arr, int arrSize) {

   int hashTableSize = 100;

   node_t  **hashTable = (node_t*)malloc(sizeof(*hashTable)*hashTableSize);

   for ( int i=0;i<arrSize;i++ ){

      if ( hashTable[i]->value )

   }

}


int main(){

   int array[7] = {5, 6, 1, -2, 0, 8, 3};

   printf("%d\n", checkIfExist(array, 7));

   return 0;
}
