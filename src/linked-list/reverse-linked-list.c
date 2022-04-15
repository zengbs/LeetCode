// TITLE: reverse linked list
// TAG: linked-list, recursion
// LEVEL: easy

// ============================================================================
// Key: https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif
// ============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedList.h"


// ==========================================================
// Step1:
//         prev   curr   next
//         NULL   |a3|-->|a2|-->|a1|-->NULL
// Step2:
//         prev   curr   next
//         NULL<--|a3|   |a2|-->|a1|-->NULL
// Step3:
//                prev   curr   next
//         NULL<--|a3|   |a2|-->|a1|-->NULL
// Step4:
//                prev   curr   next
//         NULL<--|a3|<--|a2|   |a1|-->NULL
// Step5:
//                       prev   curr   next
//         NULL<--|a3|<--|a2|   |a1|-->NULL
// Step6:
//                       prev   curr   next
//         NULL<--|a3|<--|a2|<--|a1|   NULL
// Step7:
//                              prev   curr/next
//         NULL<--|a3|<--|a2|<--|a1|   NULL
//
// ==========================================================
node_t* reverseList( node_t* head ){


   node_t *curr, *prev, *next;

   prev = NULL;
   curr = head;

   while( curr != NULL ){
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
   }

   head = prev;

   return head;
}




int main()
{
   node_t *head = NULL;
   for (int i=0;i<10;i++) addNode( &head, i );
   printList(head);

   head = reverseList(head);

   printList(head);
   freeList(head);

   return 0;
}
