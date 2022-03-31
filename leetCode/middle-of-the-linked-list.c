// TAG: linked list
// TITLE: Middle of the Linked List
// LEVEL: easy

#include <stdio.h>
#include <stdlib.h>
#include "include/linkedList.h"



node_t *middleList(node_t *head){

   node_t *curr = head;

   int length = 0;

   // count the length of list
   while( curr != NULL ){
      length++;
      curr = curr->next;
   }

   int middleIdx = 0;

   // compute the index of the middle node
   if ( length%2 != 0 ){
      middleIdx = (length+1)/2;
   }
   else{
      middleIdx = length/2+1;

   }

   int idx = 1;

   curr = head;

   // get the middle node
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
