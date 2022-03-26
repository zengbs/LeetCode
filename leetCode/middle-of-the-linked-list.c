#include <stdio.h>
#include <stdlib.h>


struct node_s{
   int value;
   struct node_s *next;
};

typedef struct node_s node_t;

void addNode( node_t **head, int value ){
   node_t *newNode = (node_t*)malloc(sizeof(node_t));
   newNode->value = value;
   newNode->next  = *head;
   *head = newNode;
}


void printList( node_t *head ){

   node_t *curr = head;

   while( curr != NULL ){
      printf("%d ", curr->value);
      curr = curr->next;
   }

   printf("\n");
}


node_t *middleList(node_t *head){

   node_t *curr = head;

   int length = 0;

   while( curr != NULL ){
      length++;
      curr = curr->next;
   }

   int middleIdx = 0;

   if ( length%2 != 0 ){
      middleIdx = (length+1)/2;
   }
   else{
      middleIdx = length/2+1;

   }

   int idx = 1;

   curr = head;

   while( idx < middleIdx ){
      idx++;
      curr = curr->next;
   }

   return curr;
}


int main(){

   node_t *head = NULL;

   for (int i=25; i>=2; i-=3) addNode(&head, i);

   printList(head);

   node_t *middleNode = middleList( head );

   printf( "%d\n" , middleNode->value );

   return 0;
}
