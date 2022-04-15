// TITLE: Remove Nth Node From End of List
// TAG: linked-list
// LEEVEL: medium


#include <stdio.h>
#include <stdlib.h>
#include "include/linkedList.h"


node_t *removeNthFromEnd( node_t *head, int NthNodeFromEnd )
{

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
