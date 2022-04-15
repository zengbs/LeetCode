// TITLE: Intersection of Two Linked Lists
// TAG: linked-list
// LEVEL: easy

#include <stdio.h>
#include <stdlib.h>
#include "../include/tools.h"
#include "../include/linkedList.h"


int getListLength( node_t *list )
{
   int length = 0;

   node_t *curr = list;

   while( curr != NULL ){

      length++;

      curr = curr->next;
   }

   return length;
}

node_t *intersection( node_t *a, node_t *b )
{
   int diff, counter;

   diff = getListLength( a ) - getListLength( b );

   node_t *longCurr, *shorCurr;

   counter = 0;

   if ( diff > 0 ) { longCurr = a; shorCurr = b; }
   else            { longCurr = b; shorCurr = a; }

   while( shorCurr != longCurr ){

      if ( counter < abs(diff) ) {  longCurr = longCurr->next; counter++; continue; }

      shorCurr = shorCurr->next;
      longCurr = longCurr->next;
   }


   return longCurr;
}


int main(){

   // create list 1
   node_t *list1 = NULL;
   addNode( &list1, 1 );
   addNode( &list1, 2 );
   addNode( &list1, 3 );
   addNode( &list1, 4 );
   addNode( &list1, 5 );

   printList(list1);

   // create list 2
   node_t *list2 = NULL;
   addNode( &list2,  9 );
   addNode( &list2,  7 );
   printList(list2);

   // connect two linked list
   // |5|-->|4|-->|3|-->|2|-->|1|
   //                    |
   //       |7|-->|9|---/
   list2->next->next = list1->next->next->next;

   node_t *intersecNode = intersection(list1, list2);

   printf("intersecNode: %d\n", intersecNode->value);

   return 0;
}
