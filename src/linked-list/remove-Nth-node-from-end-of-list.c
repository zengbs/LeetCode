// TITLE: Remove Nth Node From End of List
// TAG: linked-list, fast-slow-pointers, dummy-node
// LEVEL: medium


#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedList.h"


node_t *removeNthFromEnd( node_t *head, int NthNodeFromEnd )
{
   node_t dummy;
   dummy.next = head;

   node_t *fast = &dummy;
   node_t *slow = &dummy;

   // advance fast pointer by NthNodeFromEnd+1 nodes
   for (int step=0; step<NthNodeFromEnd+1; step++){
      fast = fast->next;
   }

   // advance fast and slow pointers simultaneously
   while( fast ){
      fast = fast->next;
      slow = slow->next;
   }

   // remove Nth node from end of list
   slow->next = slow->next->next;

   return dummy.next;
}

int main(){

   node_t *head = NULL;

   addNode(&head, 0);
   addNode(&head, 1);
   addNode(&head, 2);
   addNode(&head, 3);
   addNode(&head, 4);

   printList(head);

   int NthNodeFromEnd = 2;

   head = removeNthFromEnd( head, NthNodeFromEnd );

   printList(head);

   return 0;
}
