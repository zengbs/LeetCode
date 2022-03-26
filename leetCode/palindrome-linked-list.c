#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node_s{
   int value;
   struct node_s *next;
};

typedef struct node_s node_t;


bool isPalindrome( node_t *head )
{


}

void addNode( node_t **head, int value )
{
   node_t *newNode = (node_t*)malloc(sizeof(node_t));

   newNode->value = value;

   newNode->next  = *head;

   *head = newNode;
}


void printList( node_t *head )
{
   node_t *curr = head;

   while( curr != NULL ){
      printf("%d ", curr->value);
      curr = curr->next;
   }
   printf("\n");
}

int main(){

   node_t *head = NULL;

   for (int i=32;i>=0;i-=3) addNode(&head, i);

   printList(head);

   return 0;
}
