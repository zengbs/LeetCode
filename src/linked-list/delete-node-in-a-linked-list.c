// TITLE: Delete Node in a Linked List
// TAG: linked-list
// LEVEL: easy

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedList.h"
#include "../include/tools.h"



//=======================================
// Step-1: |a|-->|b|-->|c|-->|d|
// Step-2: |a|-->|c|-->|c|-->|d|
// Step-3: |a|-->|c|-------->|d|
//=======================================
void deleteNode( node_t *node ){
   node->value = node->next->value;
   node_t *next = node->next;
   node->next  = node->next->next;
   free(next);
}


int main(){

   node_t *head = NULL;

   for ( int i=0; i<5; i++ ) addNode( &head, i );

   printList(head);

   deleteNode( head->next->next->next );

   printList(head);

   freeList(head);

   return 0;
}
