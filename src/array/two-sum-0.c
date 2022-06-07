// TITLE: two sum
// TAG  : array, hash, linked-list
// LEVEL: easy

// https://www.itread01.com/content/1543933144.html

// Given an array of integers arry and an integer target,
// return indices of the two numbers such that they add up to target.


// ============================================================================
// Key: * create an array-based hash table
//      * the index/value of array is stored in a node rather than the hash table itself
//      * put the value/index in the array into a newNode hashTable with the hashed value
//        where the hashed value = abs(value) % arrySize
//      * if collision, we insert a new node in the following manner:
//        (hashTable[t]) --> (oldNode)
//        (hashTable[t]) --> (newNode) --> (oldNode)
//
//      * the configuration of hash table is as follows:
//
//        |0| -> NULL
//        |1| -> node1 -> NULL
//        |2| -> NULL
//        |3| -> node2 -> node3 -> NULL
//        |4| -> NULL
//
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// =============================================================================
//  value : the value to be inseted into linked list
//  index : the index of the value in the array given by the problem
// =============================================================================

struct node_s {
    long value;
    int index;
    struct node_s* next;
};

typedef struct node_s node_t;

// =============================================================================
// Description : put the value in the arry into the hashTable with the index hash(value)
//               where hash(value) = abs(value) % arrySize
//
//               --> if collision, we insert a new node in the following manner:
//                   (hashTable[t]) --> (hashTable[t]->next)
//                   (hashTable[t]) --> (newNode) --> (hashTable[t]->next)
//
//
// Input       : hashTable : chaining hash table
//               value     : the value to be inseted into linked list
//               index     : the index of the value in the array given by the problem
//               arrySize  : the array size given by the problem
//
// Output      : none
// =============================================================================

void insert(node_t** hashTable, long value, int index, int arrySize) {
    int t = abs(value) % arrySize;

    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->value = value;
    newNode->index = index;
    newNode->next = hashTable[t]->next;
    hashTable[t]->next = newNode;
}


// =============================================================================
// Input  : hashTable : chaining hash table
//          target    : the element we are looking for
//          arrySize  : array size given by the problem
//
// Output : the index of the target in a chain
//          --> return -1 if the target is not found
// =============================================================================

int search(node_t** hashTable, long target, int arrySize) {
    int index = abs(target) % arrySize;
    node_t* indexNext = hashTable[index]->next;

    while(indexNext) {
        if(indexNext->value == target) {
            return indexNext->index;
        }
        indexNext = indexNext->next;
    }

    return -1;
}


void freeHashTable(node_t** hashTable, int arrySize) {
    int i = 0;
    node_t *temp = NULL, *delete = NULL;
    for(i = 0; i < arrySize; i++) {
        temp = hashTable[i];
        delete = temp;

        while(temp) {
            delete = temp;
            temp = temp->next;
            free(delete);
        }
    }
    free(hashTable);
}


int* twoSum(int* arry, int arrySize, int target) {
    int i = 0;
    int index = 0;
    int* result = NULL;

    // allocate memory for hashTable with the size of arrySize
    node_t** hashTable = (node_t**)malloc(arrySize * sizeof(node_t*));

    // allocate memory for all head nodes in the hashTable
    for(i = 0; i < arrySize; i++) hashTable[i] = (node_t*)calloc(1, sizeof(node_t));

    // initialize all `next` nodes are NULL
    for(i = 0; i < arrySize; i++) hashTable[i]->next = NULL;

    // loop over the hashTable
    for(i = 0; i < arrySize; i++){

        // search the index of complement of the target in the hashTable
        index = search(hashTable, target - arry[i], arrySize);

        // insert a new node following the head node if the complement is not found
        if(-1 == index) insert(hashTable, arry[i], i, arrySize);

        // return the indices of the target and of its complement
        else{
            result = (int*)malloc(sizeof(int) * 2);
            result[0] = index;
            result[1] = i;
            freeHashTable(hashTable, arrySize);
            return result;
        }
    }

    freeHashTable(hashTable, arrySize);

    return result;
}


# define ARRY_SIZE 3

int main()
{
  int arrySize = ARRY_SIZE;
  int arry[ARRY_SIZE] = {3,2,4};

  int target = 6;
  int *returnArray = NULL;

  returnArray = twoSum( arry,  arrySize, target);

  if (returnArray==NULL) {printf("returnArray=NULL!\n");exit(0);}

  printf("%d  ", returnArray[0]);
  printf("%d\n", returnArray[1]);

  free(returnArray);

  return 0;
}
