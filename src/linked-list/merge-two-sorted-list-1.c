#include <stdio.h>
#include <stdlib.h>

struct node_s{
   struct node_s *next;
   int value;
};


typedef struct node_s node_t;

void printList( node_t *head )
{
   if ( head == NULL ) { printf("\n"); return; }

   node_t *curr = head;

   while( curr ){
      printf("%d ", curr->value);
      curr = curr->next;
   }
   printf("\n");
}


void freeList( node_t *head ){

   node_t *cur = head;

   while( cur != NULL ){
      node_t *next = cur->next;
      free(cur);
      cur = next;
   }
}


void addNode( node_t **head, int value ){

   node_t *newNode = (node_t*)malloc(sizeof(node_t));

   newNode->value = value;
   newNode->next  = *head;
   *head  = newNode;
}


void moveNode(node_t **src, node_t **des){

   node_t *srcNext = (*src)->next;

   (*src)->next = *des;

   *des = *src;

   *src = srcNext;

}


node_t * mergeSortedList( node_t *list1, node_t *list2 ){

   node_t dummy;
   dummy.next = NULL;

   node_t *tail = &dummy;

   while( ( list1 != NULL ) && (list2 != NULL) ){

      if ( list1->value > list2->value ) moveNode( &list2, &(tail->next) );
      else                               moveNode( &list1, &(tail->next) );

      tail = tail->next;
   }

   if ( list1 == NULL )    tail->next = list2;
   else                    tail->next = list1;

   return dummy.next;

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
   list3 = mergeSortedList( list1, list2 );

   // print result
   printList(list3);


   // free memory
   freeList(list3);

   return 0;
}
