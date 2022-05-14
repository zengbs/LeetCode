// TITLE: sort list
// TAG: sorting, linked-list
// LEVEL: medium

// https://youtu.be/KAgkvtKMbwY
// https://hackmd.io/@kenjin/HksBkpUHr

#include <stdio.h>
#include <stdlib.h>


struct node_s {
   struct node_s *next;
   int value;
};


typedef struct node_s node_t;


void addNode( node_t **head, int value ){

   node_t *newNode = (node_t*)malloc(sizeof(node_t));

   newNode->next  = *head;
   newNode->value = value;

   *head = newNode;
}


// Even number of nodes: return the left middle node
// Odd number of nodes: return the middle node
node_t getMiddleNode( node_t *head ){


}


void mergeSort( node *head ){

}


void printList( node_t *head ){

   node_t node = *head;

   while( node != NULL ){
      printf("%d ", node->value);
      node = node->next;
   }
   printf("\n");
}
