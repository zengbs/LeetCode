#include <stdio.h>
#include <stdlib.h>


struct node_s{
   int value;
   struct node_s *next;
};

typedef struct node_s node_t;


// |3|-->|4|-->|4|-->|4|-->|5|-->|9|-->NULL
// |3|-->|4|-------->|4|-->|5|-->|9|-->NULL
// |3|-->|4|-------------->|5|-->|9|-->NULL
void deleteDuplicates(node_t *head)
{
   node_t *curr = head;
   node_t *curr_next_next;

   while( curr != NULL ){

      if (curr->next == NULL) break;

      if ( curr->value == curr->next->value ){
         curr_next_next = curr->next->next;
         free(curr->next);
         curr->next = curr_next_next;
      }
      else{
         curr = curr->next;
      }
   }

}



void printList( node_t *head )
{
   node_t *curr = head;

   while( curr ){
      printf("%d ", curr->value);
      curr = curr->next;
   }
   printf("\n");
}

void addNode(  node_t **head, int value )
{
   node_t *newNode = (node_t*)malloc(sizeof(node_t));


   newNode->value = value;
   newNode->next = *head;

   *head = newNode;
}


int main()
{
   node_t *head = NULL;

   addNode( &head, 3 );
   addNode( &head, 4 );
   addNode( &head, 4 );
   addNode( &head, 4 );
   addNode( &head, 5 );
   addNode( &head, 9 );
   addNode( &head, 9 );
   addNode( &head, 9 );
   addNode( &head, 9 );
   addNode( &head, 9 );
   addNode( &head, 9 );
   addNode( &head, 9 );
   addNode( &head, 9 );
   addNode( &head, 9 );

   printList(head);

   deleteDuplicates(head);

   printList(head);

   return 0;
}
