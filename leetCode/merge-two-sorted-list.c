// TITLE: merge sorted linked list
// TAG:   linked list
// LEVEL: easy
// https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/

#include <stdio.h>
#include <stdlib.h>


struct node_s{
   int value;
   struct node_s *next;
};

typedef struct node_s node_t;



void addNode( node_t **head, int newValue ){
   node_t* newNode = (node_t*)malloc(sizeof(node_t));
   newNode->next = *head;
   newNode->value = newValue;
   *head = newNode;
}



void printList( node_t *head ){

   node_t *curr = head;

   while( curr != NULL ){
      printf("%2d ", curr->value);
      curr = curr->next;
   }
   printf("\n");
}



void freeList( node_t **head ){

   node_t *curr = *head;

   while( curr != NULL ){
      node_t *next = curr->next;
      free(curr);
      curr = next;
   }
}
//=====================================================
// Step 1:
//                   cur1
//           list1 : |2|-->|9|
//           list2 : |2|-->|7|-->|8|
//                   cur2
//
//           list3:  |2|
//-----------------------------------------------------
// Step 2:
//                   cur1
//           list1 : |2|-->|9|
//           list2 : |2|-->|7|-->|8|
//                         cur2
//
//           list3:  |2|-->|2|
//-----------------------------------------------------
// Step 3:
//                         cur1
//           list1 : |2|-->|9|
//           list2 : |2|-->|7|-->|8|
//                         cur2
//
//           list3:  |2|-->|2|-->|7|
//-----------------------------------------------------
// Step 4:
//                         cur1
//           list1 : |2|-->|9|
//           list2 : |2|-->|7|-->|8|
//                               cur2
//
//           list3:  |2|-->|2|-->|7|-->|8|
//           list3:  |2|-->|2|-->|7|-->|8|-->|9|
//=====================================================
void mergeSortedList( node_t **list1, node_t **list2, node_t **list3 )
{
   node_t *curr1 = *list1;
   node_t *curr2 = *list2;


   while ( curr1 != NULL || curr2 != NULL ){

      if ( curr1 != NULL && curr2 != NULL && ( curr1->value >= curr2->value ) ){
         addNode( list3, curr2->value );
         curr2 = curr2->next;
      }
      else if ( curr1 != NULL && curr2 != NULL && ( curr1->value < curr2->value ) ){
         addNode( list3, curr1->value );
         curr1 = curr1->next;
      }
      else if ( curr1 == NULL && curr2 != NULL ){
         addNode( list3, curr2->value );
         curr2 = curr2->next;
      }
      else if ( curr2 == NULL && curr1 != NULL ){
         addNode( list3, curr1->value );
         curr1 = curr1->next;
      }
      else { printf("something wrong!\n"); exit(0); }

   }
}


int main(){

   // create list 1
   node_t *list1 = NULL;
   for (int i=9;i>=-5;i--)   addNode( &list1, i );
   printList(list1);

   // create list 2
   node_t *list2 = NULL;
   for (int i=25;i>=0;i-=3) addNode( &list2, i );
   printList(list2);

   // merge sorted list
   node_t *list3 = NULL;
   mergeSortedList( &list1, &list2, &list3 );

   // print result
   printList(list3);


   // free memory
   freeList(&list1);
   freeList(&list2);
   freeList(&list3);

   return 0;
}
