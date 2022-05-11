// TITLE: heaters
// TAG: binary-search, array, sorting
// LEVEL: medium


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


void swap( int *x, int *y ){
   if ( x != y ){
      *x ^= *y;
      *y ^= *x;
      *x ^= *y;
   }
}

int partition( int *array, int l, int r ){

   int pivotIdx = l + (r-l)/2;

   swap( &array[pivotIdx], &array[r] );

   int i = l;

   for( int j=l;j<r;j++ ){
      if ( array[j] <= array[r] ){
         swap( &array[i], &array[j] );
         i++;
      }
   }

   swap( &array[i], &array[r] );

   return i;
}


void quickSort( int *array, int l, int r ){

   if ( r <= l ) return;

   int q = partition(array, l, r);

   quickSort(array, l  , q-1);
   quickSort(array, q+1, r  );
}


// given an house's position, return the nearest heater's position
int binarySearch( int *heaters, int heaterSize, int housePosition ){

   int l = -1;
   int r = heaterSize;
   int m;

   while( l+1 != r ){

      m = l + (r-l)/2;

      if ( heaters[m] < housePosition ) l = m;
      else                              r = m;
   }


   if ( 0 <=l && r <= heaterSize-1 ){

      if ( (housePosition - heaters[l]) > (heaters[r] - housePosition )) return r;
      else                                                               return l;
   }
   else if ( l < 0 ) return r;
   else              return l;
}


int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){

   int nearestHeaterPosition;
   int *minimumRadius = (int*)calloc(housesSize, sizeof(int));

   // sorting heaters array
   quickSort( heaters, 0, heatersSize-1 );


   // given a house position, find the nearest heater's position
   for ( int i=0;i<housesSize;i++ ){
      nearestHeaterPosition = binarySearch(heaters, heatersSize, houses[i]);
      minimumRadius[i] = abs( heaters[nearestHeaterPosition] - houses[i] );
   }

   // find the maximum in minimumRadius[]
   int maxRadius = 0;
   for ( int i=0;i<housesSize;i++ ){
      if ( maxRadius < minimumRadius[i] ) maxRadius = minimumRadius[i];
   }

   free(minimumRadius);

   return maxRadius;
}


int main(){


   int heaters[] = { 2 };
   int heatersSize = sizeof(heaters)/sizeof(heaters[0]);

   int houses[]  = { 1, 2, 3 };
   int housesSize = sizeof(houses)/sizeof(houses[0]);

   int radius = findRadius( houses, housesSize, heaters, heatersSize );

   printf("%d\n", radius);

   return 0;
}
