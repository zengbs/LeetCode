// TITLE: Linked List Cycle II
// TAG: linked-list, fast-slow-pointers
// LEVEL: medium
// Reference: https://ithelp.ithome.com.tw/articles/10223721

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "include/linkedList.h"
#include "include/tools.h"



node_t *detectCycle( node_t *head )
{
   node_t *fast, *slow;

   fast = head;
   slow = head;

   do{

      if ( fast       == NULL ) return NULL;
      if ( fast->next == NULL ) return NULL;

      slow = slow->next;
      fast = fast->next->next;

   }while( fast != slow );


   slow = head;

   while( fast != slow ){
      fast = fast->next;
      slow = slow->next;
   }

   return fast;
}


int main(){

   node_t *head = NULL;

   addNode(&head, -4);

   node_t *tail = head;

   addNode(&head, 0);
   addNode(&head, 2);

   node_t *cycleEntry1 = head;
   tail->next = cycleEntry1;

   addNode(&head, 3);


   node_t *cycleEntry2 = detectCycle( head );

   printf("cycleEntry1 = %d\n", cycleEntry1->value);
   printf("cycleEntry2 = %d\n", cycleEntry2->value);

   return 0;
}
