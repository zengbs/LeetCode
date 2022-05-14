// TITLE: sort list
// TAG: sorting, linked-list, merge-sort
// LEVEL: medium


#include <stdio.h>
#include <stdlib.h>


struct node_s {
   struct node_s *next;
   int value;
};


typedef struct node_s node_t;

void printList( node_t *head ){

   node_t *node = head;

   while( node != NULL ){
      printf("%d ", node->value);
      node = node->next;
   }
   printf("\n");
}

void addNode( node_t **head, int value ){

   node_t *newNode = (node_t*)malloc(sizeof(node_t));

   newNode->next  = *head;
   newNode->value = value;

   *head = newNode;
}


// Even number of nodes: return the right middle node
// Odd number of nodes: return the middle node

//-------------------------------------------------
// a-b-c-d-e      ==> a-b-N & c-d-e-N
// o
//   s f
//     s   f
//-------------------------------------------------
// a-b-c-d-e-f-N  ==> a-b-c-N & d-e-f-N
// o
//   s f
//     s   f
//       s     f
//-------------------------------------------------
// a-b-N          ==> a-N & b-N
// o
//   s f
//-------------------------------------------------
// base case
// a-N            ==> a-N & a-N
// o
//-------------------------------------------------

void splitList( node_t **head, node_t **left, node_t **right ){

   node_t *fast     = *head;
   node_t *slow     = *head;
   node_t *prevSlow = *head;

   while( fast != NULL && fast->next != NULL ){
      fast = fast->next->next;
      prevSlow = slow;
      slow = slow->next;
   }

   prevSlow->next = NULL;

   *left  = *head;
   *right = slow;
}

void moveNode( node_t **src, node_t **det ){

   node_t *curr = *src;

   *src = (*src)->next;

   curr->next = *det;

   *det = curr;
}



void merge( node_t **head, node_t *a, node_t *b ){

   node_t dummy, *tail;

   tail = &dummy;

   dummy.next = NULL;


   while ( 1 ){

      if ( a == NULL ) { tail->next = b; break; }
      if ( b == NULL ) { tail->next = a; break; }

      if ( a->value <= b->value )
         moveNode( &a, &(tail->next) );
      else
         moveNode( &b, &(tail->next) );

      tail = tail->next;

   }

   *head = dummy.next;

}

void mergeSort( node_t **head ){

   node_t *left  = NULL;
   node_t *right = NULL;

   // split list
   splitList( head, &left, &right );

   // base case
   if ( left == right ) return;

   // split left sublist
   mergeSort( &left );

   // split right sublist
   mergeSort( &right );

   merge( head, left, right );
}





int main(){

   // create list
   node_t *list = NULL;
   addNode( &list, 5 );
   addNode( &list, 3 );
   addNode( &list, 1 );
   addNode( &list, 5 );
   addNode( &list, 9 );
   addNode( &list, 8 );
   addNode( &list, 99 );
   addNode( &list, 98 );
   addNode( &list, 101 );
   addNode( &list, 102 );
   addNode( &list, 54 );
   addNode( &list, 82 );
   addNode( &list, 64 );
   addNode( &list, 36 );
   printList(list);

   // merge sorted list
   mergeSort( &list );

   // print result
   printList(list);


   return 0;
}
