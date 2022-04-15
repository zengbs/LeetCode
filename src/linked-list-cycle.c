// TAG: linked-list, fast-slow pointers


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "include/linkedList.h"
#include "include/tools.h"

bool hasCycle(node_t *head) {

   node_t *fast = head;
   node_t *slow = head;


   while ( fast != NULL && fast->next != NULL ){

      fast = fast->next->next;
      slow = slow->next;


      if ( fast == slow ) return true;
   }

   return false;
}




int main(){

   node_t *head = NULL;

   for ( int i=0; i<5; i++ ) addNode( &head, i );

   printList(head);

   if ( hasCycle(head) ) printf("cycled list\n");
   else                  printf("non-cycled list\n");

   freeList(head);

   return 0;
}
