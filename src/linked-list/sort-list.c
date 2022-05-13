// TITLE: sort list
// TAG: sorting, linked-list
// LEVEL: medium

// https://youtu.be/KAgkvtKMbwY

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


void printList( node_t *head ){

   node_t node = *head;

   while( node != NULL ){
      printf("%d ", node->value);
      node = node->next;
   }
   printf("\n");
}



