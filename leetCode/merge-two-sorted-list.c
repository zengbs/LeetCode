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

   node_t *cur = head;

   while( cur != NULL ){
      printf("%2d ", cur->value);
      cur = cur->next;
   }
   printf("\n");
}



void freeList( node_t **head ){

   node_t *cur = *head;

   while( cur != NULL ){
      node_t *next = cur->next;
      free(cur);
      cur = next;
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
   node_t *cur1 = *list1;
   node_t *cur2 = *list2;


   while ( cur1 != NULL || cur2 != NULL ){

      if ( cur1 != NULL && cur2 != NULL && ( cur1->value >= cur2->value ) ){
         addNode( list3, cur2->value );
         cur2 = cur2->next;
      }
      else if ( cur1 != NULL && cur2 != NULL && ( cur1->value < cur2->value ) ){
         addNode( list3, cur1->value );
         cur1 = cur1->next;
      }
      else if ( cur1 == NULL && cur2 != NULL ){
         addNode( list3, cur2->value );
         cur2 = cur2->next;
      }
      else if ( cur2 == NULL && cur1 != NULL ){
         addNode( list3, cur1->value );
         cur1 = cur1->next;
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
