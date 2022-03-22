
// TITLE: two sum
// TAG: array hash
// LEVEL: easy

// https://www.itread01.com/content/1543933144.html

// Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct node {
    long val;
    int index;
    struct node* next;
};


void insert(struct node** hashTable, long val, int index, int n) {
    int t = abs(val) % n;
    struct node* temp = hashTable[t];
    // head-add
    struct node* add = (struct node*)malloc(sizeof(struct node));
    add->val = val;
    add->index = index;
    add->next = temp->next;
    temp->next = add;
}


int search(struct node** hashTable, long target, int n) {
    int index = abs(target) % n;
    struct node* temp = hashTable[index]->next;
    while(temp) {
        if(temp->val == target) {
            return temp->index;
        }
        temp = temp->next;
    }
    return -1;
}


void freeHashTable(struct node** hashTable, int n) {
    int i = 0;
    struct node *temp = NULL, *delete = NULL;
    for(i = 0; i < n; i++) {
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


int* twoSum(int* nums, int numsSize, int target) {
    int i = 0, j = 0;
    int n = numsSize, index = 0;
    int* result = NULL;
    struct node** hashTable = (struct node**)malloc(n * sizeof(struct node*));
    // init head node
    for(i = 0; i < n; i++)
        hashTable[i] = (struct node*)calloc(1, sizeof(struct node));
    for(i = 0; i < n; i++) {
        index = search(hashTable, target - nums[i], n);
        if(-1 == index)
            insert(hashTable, nums[i], i, n);
        else {
            result = (int*)malloc(sizeof(int) * 2);
            result[0] = index;
            result[1] = i;
            freeHashTable(hashTable, n);
            return result;
        }
    }
    freeHashTable(hashTable, n);
    return result;
}



int main()
{

  int returnSize;
  int ASize = 3;
  int A[3] = {3,2,4};
  int target = 6;
  int *returnArray = NULL;

  returnArray = twoSum( A,  ASize, target);

  if (returnArray==NULL) {printf("returnArray=NULL!\n");exit(0);}

  printf("%d  ", returnArray[0]);
  printf("%d\n", returnArray[1]);

  return 0;
}
