#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b){
   if ( a != b ){
      *a ^= *b;
      *b ^= *a;
      *a ^= *b;
   }
}

int partition(int *array, int l, int r){

   int p = l+(r-l)/2;

   swap(&array[p], &array[r]);

   int i = l;

   for ( int j=l;j<r;j++ ){
     if ( array[j] < array[r] ){ // ascending order
        swap(&array[i], &array[j]);
        i++;
     }
   }

   swap(&array[i], &array[r]);

   return i;
}


void quickSort(int *array, int l, int r){

   if ( r <= l ) return;

   int p = partition(array, l, r);

   quickSort(array, l  , p-1);
   quickSort(array, p+1,   r);

}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int main(){

   int arrSize = 3;

   int *array     = (int*)malloc(arrSize*sizeof(int));
   int *array_ref = (int*)malloc(arrSize*sizeof(int));

   srand(time(NULL));

   for ( int i=0;i<arrSize;i++ ){
      array[i] = rand();
      array_ref[i] = array[i];
   }

   array[0] = array_ref[0] = 2;
   array[1] = array_ref[1] = 2;
   array[2] = array_ref[2] = 1;

   quickSort(array, 0, arrSize-1);
   qsort (array_ref, arrSize, sizeof(int), compare);

   for ( int i=0;i<arrSize;i++ ){
      printf("%d ", array[i]);
      if ( array_ref[i] != array[i] ){
         printf("Fail!\n");
         return 0;
      }
   }

   printf("Pass!\n");
   return 0;
}
