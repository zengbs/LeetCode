// TITLE: palindrome linked list
// TAG: stack, reverse linked list, recursion
// LEVEL: easy

// https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/

//                                   time    space
// METHOD 1 (use a Stack)            O(n)
// METHOD 2 (by reversing the list)  O(n)     O(1)
// METHOD 3 (use Recursion)          O(n)     O(n)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/linkedList.h"

// ==============================================
// odd number nodes
//        s f
//        |1|-->|2|-->|3|-->|4|-->|5|-->NULL
// fastSteps = 0
//---------------------------------------------
//         s     f
//        |1|-->|2|-->|3|-->|4|-->|5|-->NULL
// fastSteps = 1
//---------------------------------------------
//        sP    s,sN   f
// NULL<--|1|   |2|-->|3|-->|4|-->|5|-->NULL
// fastSteps = 2
//---------------------------------------------
//        sP    s,sN         f
// NULL<--|1|   |2|-->|3|-->|4|-->|5|-->NULL
// fastSteps = 3
//---------------------------------------------
//              sP    s,sN         f
// NULL<--|1|<--|2|   |3|-->|4|-->|5|-->NULL
// fastSteps = 4
//---------------------------------------------
//              sP    s,sN              f
// NULL<--|1|<--|2|   |3|-->|4|-->|5|-->NULL
// fastSteps = 5
// ==============================================
// even number nodes
//        s f
//        |1|-->|2|-->|3|-->|4|-->NULL
// fastSteps = 0
//---------------------------------------
//         s     f
//        |1|-->|2|-->|3|-->|4|-->NULL
// fastSteps = 1
//---------------------------------------
//        sP    s,sN   f
// NULL<--|1|   |2|-->|3|-->|4|-->NULL
// fastSteps = 2
//---------------------------------------
//        sP    s,sN         f
// NULL<--|1|   |2|-->|3|-->|4|-->NULL
// fastSteps = 3
//---------------------------------------
//              sP    s,sN        f
// NULL<--|1|<--|2|   |3|-->|4|-->NULL
// fastSteps = 4
// ==============================================



bool isPalindrome( node_t *head )
{
   node_t *fast = head;
   node_t *slow = head;

   node_t *slowPrev = NULL;
   node_t *slowNext = NULL;

   int fastSteps = 0;

   while( fast != NULL ){

      // advance the fast pointer
      fast = fast->next;

      if (fastSteps%2 == 1){

         slowNext = slow->next;

         slow->next = slowPrev;

         slowPrev = slow;

         // advance the slow pointer
         slow = slowNext;
      }

      fastSteps++;

   }


   node_t *ptr1 = NULL;
   node_t *ptr2 = NULL;

   if ( fastSteps == 1 ) return true;

   // odd number nodes
   if ( fastSteps%2 == 1 ){
      ptr1 = slowNext->next;
      ptr2 = slowPrev;
   }
   // even number nodes
   else{
      ptr1 = slowPrev;
      ptr2 = slowNext;
   }

   // compare the two linked lists
   while( ptr1 != NULL ){

      if ( ptr1->value != ptr2->value ) return false;

      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
   }

   return true;
}


int main(){

   node_t *head = NULL;

   addNode(&head, 1);
   addNode(&head, 2);
   addNode(&head, 3);
   addNode(&head, 4);
   addNode(&head, 3);
   addNode(&head, 2);
   addNode(&head, 1);

   if(isPalindrome(head)) printf("It is a palindrome!\n");
   else                   printf("It is not a palindrome!\n");

   return 0;
}
