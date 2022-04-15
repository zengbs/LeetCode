#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__


struct node_s{
   int value;
   struct node_s *next;
};

typedef struct node_s node_t;



void printList( node_t *head )
{
   if ( head == NULL ) { printf("\n"); return; }

   node_t *curr = head;

   while( curr ){
      printf("%d ", curr->value);
      curr = curr->next;
   }
   printf("\n");
}

// ==========================================================
//           head
// Step1:    |a1|-->NULL
// Step2:    |a2|-->|a1|-->NULL
// Step3:    |a3|-->|a2|-->|a1|-->NULL
// ==========================================================
void addNode(  node_t **head, int value )
{
   node_t *newNode = (node_t*)malloc(sizeof(node_t));

   newNode->value = value;
   newNode->next = *head;

   *head = newNode;
}


void freeList( node_t *head ){

   node_t *cur = head;

   while( cur != NULL ){
      node_t *next = cur->next;
      free(cur);
      cur = next;
   }
}

#endif
