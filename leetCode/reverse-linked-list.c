// TAG: linked list, recursion
// TITLE: reverse linked list
// LEVEL: easy

// ============================================================================
// Key: https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif
// ============================================================================
#include <stdio.h>
#include <stdlib.h>

struct node_s{
  int value;
  struct node_s* next;
};

typedef struct node_s node_t;


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



// ==========================================================
//           head
// Step1:    |a1|-->NULL
// Step2:    |a2|-->|a1|-->NULL
// Step3:    |a3|-->|a2|-->|a1|-->NULL
// ==========================================================
void addNode( node_t **head, int newValue ){
   node_t* newNode = (node_t*)malloc(sizeof(node_t));
   newNode->next = *head;
   newNode->value = newValue;
   *head = newNode;
}



void printList( node_t* head )
{
    node_t *curr = head;

    while( curr != NULL ){
       printf("%d ", curr->value);
       curr = curr->next;
    }
    printf("\n");
}



void freeList( node_t** head )
{
  node_t *curr = *head;
  node_t *next;

   while( curr != NULL ){
      next = curr->next;
      free(curr);
      curr = next;
   }
}



int main()
{
   node_t *head = NULL;
   for (int i=0;i<10;i++) addNode( &head, i );
   printList(head);

   head = reverseList(head);

   printList(head);
   freeList(&head);

   return 0;
}
