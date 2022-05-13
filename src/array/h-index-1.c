// TITLE: H-index
// LEVEL: medium
// TAG: sorting, array


#include<stdio.h>
#include<stdlib.h>

void swap( int *a, int *b ){
   if( a != b ){
      *a ^= *b;
      *b ^= *a;
      *a ^= *b;
   }
}

//  a   b    a^b
//  0   0     0
//  0   1     1
//  1   0     1
//  1   1     0

int partition(int *array, int l, int r){

   int p = l+(r-l)/2;

   swap(&array[p], &array[r]);

   int i = l;

   for( int j=l;j<r;j++ ){ // j=0
      if ( array[j] < array[r] ){ // array[p]
         swap(&array[i], &array[j]);
         i++;
      }
   }

   swap(&array[i], &array[r]); // forget

   return i;
}

void quickSort(int *array, int l, int r){

   if ( r <= l ) return;

   int p = partition(array, l, r);

   quickSort(array,l,p-1);
   quickSort(array,p+1,r);

}

int hIndex(int* citations, int numsPaper){

   quickSort(citations, 0, numsPaper-1);

   int maxHIdx = numsPaper;

   for ( int hIdx=maxHIdx; hIdx>=1; hIdx-- ){
// 0,1,3,5,6
      if ( citations[maxHIdx-hIdx] >= hIdx ) return hIdx;

   }

   return 0;
}


int main(){

   int citations[] = {3,0,6,1,5};

   int numsPaper = sizeof(citations)/sizeof(citations[0]);

   printf("%d\n", hIndex(citations, numsPaper));

}
