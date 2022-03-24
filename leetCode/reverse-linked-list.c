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
//         NULL<--|a3|<--|a2|<--|a1|     NULL
//
// ==========================================================
void reverseList( node_t** head ){


   node_t *curr, *prev, *next;

   curr = *head;
   prev = NULL;

   while( curr != NULL ){
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
   }

   *head = prev;
}

// ==========================================================
// head:|a1|:     |a1|-->NULL
// head:|a2|:     |a2|-->|a1|-->NULL
// head:|a3|:     |a3|-->|a2|-->|a1|-->NULL
// ==========================================================

void createList( node_t** head, int length ){

    int value = 0;
    int leng = 0;

    (*head) = (node_t*)malloc(sizeof(node_t));

    (*head)->next = NULL;
    (*head)->value = value++;

    while ( leng < length-1 ){
       node_t* curr = (node_t*)malloc(sizeof(node_t));
       curr->value = value++;
       curr->next  = *head;
       *head = curr;
       leng++;
    }

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



int main()
{
   node_t *head = NULL;
   createList(&head, 10);
   printList(head);
   reverseList(&head);
   printList(head);

   return 0;
}
