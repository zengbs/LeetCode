// TITLE: Merge Sorted Array
// TAG: array
// LEVEL: easy

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
   int *ans = (int*)malloc( (m+n)*sizeof(int) );

   int idx1 = 0;
   int idx2 = 0;
   int idx  = 0;

   while( idx1 < m && idx2 < n )
      ans[idx++] = ( nums1[idx1] > nums2[idx2] ) ? nums2[idx2++] : nums1[idx1++];

   int *longArry = ( idx1 == m ) ? nums2 : nums1;
   int longIdx   = ( idx1 == m ) ? idx2 : idx1 ;


   for( ;idx<m+n;idx++ )      ans[idx] = longArry[longIdx++];

   for ( int i=0; i<m+n; i++ ) printf("%d ", ans[i]);;
   printf("\n");
}


int main (){

   int arr1[] = { 2 };
   int arr2[] = { 1 };

   int arr1Size = sizeof(arr1)/sizeof(arr1[0]);
   int arr2Size = sizeof(arr2)/sizeof(arr2[0]);

   int m = 1;
   int n = 1;

   merge(arr1, arr1Size, m, arr2, arr2Size, n ) ;

   return 0;
}
