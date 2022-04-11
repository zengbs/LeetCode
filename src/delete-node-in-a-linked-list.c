#include <stdio.h>
#include <stdlib.h>
#include "include/linkedList.h"
#include "include/tools.h"


// |a|-->|b|-->|c|-->|d|
// |a|---|c|-------->|d|

void deleteNode( node_t *node ){

   if ( node->next == NULL ){

      //free(node);
      node = NULL;

   }
   else if ( node->next->next == NULL ){

      node->value = node->next->value;
      free(node->next);
      node->next = NULL;

   }
   else{

      node->value = node->next->value;
      node_t *next = node->next;
      node->next  = node->next->next;
      free(next);
   }
}


int main(){

   node_t *head = NULL;

   for ( int i=0; i<5; i++ ) addNode( &head, i );

   printList(head);

   deleteNode( head->next->next->next->next );

   printList(head);

   freeList(head);

   return 0;
}
