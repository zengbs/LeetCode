// TITLE: Middle of the Linked List
// TAG: linked-list, fast-slow-pointers
// LEVEL: easy

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "include/linkedList.h"

// Using fast and slow pointers


// |a|-->|b|-->|c|-->|d|-->|e|
// |a|-->|b|-->|c|-->|d|

node_t *middleList(node_t *head){

   node_t *slow = head;
   node_t *fast = head;

   int fastSteps = 0;

   //  The stop criteria should nnot be fast != NULL
   while( fast->next != NULL && fast->next->next != NULL ){

      fast = fast->next->next;
      slow = slow->next;

      fastSteps++;

   }


   if ( fastSteps%2 == 0 ) return slow;
   else                    return slow->next;
}


int main(){

   node_t *head = NULL;

   addNode(&head, 5);
   addNode(&head, 5);
   addNode(&head, 4);
   addNode(&head, 3);
   addNode(&head, 2);
   addNode(&head, 1);

   printList(head);

   node_t *middleNode = middleList( head );


   printf( "%d\n" , middleNode->value );

   return 0;
}
