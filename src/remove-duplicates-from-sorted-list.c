// TITLE: Remove Duplicates from Sorted List
// TAG: linked list
// LEVEL: easy

#include <stdio.h>
#include <stdlib.h>
#include "include/linkedList.h"



//========================================================
// c  : curr
// cn : curr->next
// cnn: curr->next->next
//
//
// c     cn
// |3|-->|4|-->|4|-->|4|-->|5|-->|9|-->NULL
//
//       c     cn
// |3|-->|4|-->|4|-->|4|-->|5|-->|9|-->NULL
//
//       c     cn    cnn
// |3|-->|4|-->|4|-->|4|-->|5|-->|9|-->NULL
//
//       c           cnn
// |3|-->|4|-------->|4|-->|5|-->|9|-->NULL
//
//       c           cn
// |3|-->|4|-------->|4|-->|5|-->|9|-->NULL
//
//       c           cn    cnn
// |3|-->|4|-------->|4|-->|5|-->|9|-->NULL
//
//       c                 cnn
// |3|-->|4|-------->|4|-->|5|-->|9|-->NULL
//
//       c                 cn
// |3|-->|4|-------------->|5|-->|9|-->NULL
//
//                         c     cn
// |3|-->|4|-------------->|5|-->|9|-->NULL
//
//                               c     cn
// |3|-->|4|-------------->|5|-->|9|-->NULL
//========================================================

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
