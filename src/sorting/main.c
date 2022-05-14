#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/array.h"

//#define MERGE_SORT
#define QUICK_SORT

#ifdef MERGE_SORT
void mergeSort(int arr[], int l, int r);
#endif

#ifdef QUICK_SORT
void quickSort(int *arr, int l, int r);
#endif

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{

  int arrSize = 200000;

   int *array     = (int*)malloc(arrSize*sizeof(int));
   int *array_ref = (int*)malloc(arrSize*sizeof(int));

   srand(time(NULL));

   for ( int i=0;i<arrSize;i++ ){
      array[i] = rand();
      array_ref[i] = array[i];
   }

   //array[0] = 2;
   //array[1] = 3;
   //array_ref[0] = 2;
   //array_ref[1] = 3;
#  ifdef MERGE_SORT
   mergeSort(array, 0, arrSize);
#  endif

#  ifdef QUICK_SORT
   quickSort(array, 0, arrSize-1);
#  endif

   qsort (array_ref, arrSize, sizeof(int), compare);

   for ( int i=0;i<arrSize;i++ ){
      if ( array_ref[i] != array[i] ){
         printf("Fail!\n");
         return 0;
      }
   }

   printf("Pass!\n");
   return 0;
}

