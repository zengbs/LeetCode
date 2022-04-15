// TITLE: Remove Linked List Elements
// TAG: linked-list, dummy-node
// LEVEL: easy

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "include/linkedList.h"
#include "include/tools.h"

// d: dummy
// c: curr
// p: prev

//==============================================
// |d|-->|6|-->|1|-->|6|-->|6|-->|2|-->|6|-->|N|
//  p     c
//
//-----------------------------------------------
// |d|   |6|-->|1|-->|6|-->|6|-->|2|-->|6|-->|N|
//  |_____|
//  p           c
//
//-----------------------------------------------
// |d|   |6|-->|1|-->|6|-->|6|-->|2|-->|6|-->|N|
//  |___________|
//              p     c
//
//-----------------------------------------------
// |d|   |6|-->|1|-->|6|-->|6|-->|2|-->|6|-->|N|
//  |__________| |__________|
//              p           c
//
//-----------------------------------------------
// |d|   |6|-->|1|   |6|-->|6|-->|2|-->|6|-->|N|
//  |__________| |________________|
//              p                 c
//
//-----------------------------------------------
// |d|   |6|-->|1|   |6|-->|6|-->|2|-->|6|-->|N|
//  |__________| |________________|
//                                p     c
//
//-----------------------------------------------
// |d|   |6|-->|1|   |6|-->|6|-->|2|-->|6|-->|N|
//  |__________| |_______________| |__________|
//                                p           c
//
//==============================================


node_t *removeElements(node_t *head, int value)
{
   node_t dummy, *curr, *prev;

   dummy.next = head;

   curr = head;

   prev = &dummy;

   while( curr != NULL ){

      if ( curr->value == value ) prev->next = curr->next;
      else                        prev = curr;

      curr = curr->next;
   }

   return dummy.next;

}


int main(){

   node_t *head = NULL;

   addNode( &head, 6 );
   addNode( &head, 2 );
   addNode( &head, 6 );
   addNode( &head, 6 );
   addNode( &head, 1 );
   addNode( &head, 6 );

   printList(head);

   head = removeElements(head, 6);

   printList(head);

   freeList(head);

   return 0;
}
