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


// |a|-->|b|-->|c|-->|b|-->|a|
// |a|-->|b|-------->|b|-->|a|

bool isPalindrome( node_t *head )
{


}


int main(){

   node_t *head = NULL;

   for (int i=32;i>=0;i-=3) addNode(&head, i);

   printList(head);

   return 0;
}
