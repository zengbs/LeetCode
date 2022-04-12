// TAG: dummy pointer

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "include/linkedList.h"
#include "include/tools.h"


node_t *removeElements(node_t *head, int value)
{
   node_t dummy;

   dummy.next = head;


   node_t *prev = &dummy;
   node_t *curr = head;

   while( curr != NULL ){

      if( curr->value == value ) prev->next = curr->next;
      else                       prev       = curr;

      curr = curr->next;

   }

   return dummy.next;
}


int main(){

   node_t *head = NULL;

   addNode( &head, 6 );
   addNode( &head, 1 );
   addNode( &head, 2 );
   addNode( &head, 3 );
   addNode( &head, 6 );
   addNode( &head, 6 );
   addNode( &head, 6 );

   printList(head);

   head = removeElements(head, 6);

   printList(head);

   freeList(head);

   return 0;
}
