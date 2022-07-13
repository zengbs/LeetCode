// TITLE: Merge Sorted Array
// TAG: array, multiple-pointer
// LEVEL: easy
// LINK: https://leetcode.com/problems/merge-sorted-array/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{

   int *mergeArray = (int*)malloc((m+n)*sizeof(int));

   int idx1 = 0;
   int idx2 = 0;
   int mergeIdx = 0;

   while( idx1 < m && idx2 < n ){
      if ( nums1[idx1] > nums2[idx2] ) mergeArray[mergeIdx++] = nums2[idx2++];
      else                             mergeArray[mergeIdx++] = nums1[idx1++];
   }

   int *remainder    = NULL;
   int  remainderIdx = 0;

   if ( idx1 < m ){
      remainder    = nums1;
      remainderIdx = idx1;
   }
   else{
      remainder    = nums2;
      remainderIdx = idx2;
   }

   while( mergeIdx < m+n )  mergeArray[mergeIdx++] = remainder[remainderIdx++];

   for (int i=0;i<m+n;i++) nums1[i] = mergeArray[i];

}


int main (){

   int arr1[] = { 1,2,3,0,0,0 };
   int arr2[] = { 2,5,6 };

   int arr1Size = sizeof(arr1)/sizeof(arr1[0]);
   int arr2Size = sizeof(arr2)/sizeof(arr2[0]);

   int m = 3;
   int n = 3;

   merge(arr1, m, m, arr2, n, n ) ;

   for( int i=0;i<m+n;i++ )  printf("%d ", arr1[i]);

   printf("\n");

   return 0;
}
