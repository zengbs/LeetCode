// TITLE: heaters
// TAG: binary-search, array
// LEVEL: medium


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){


   int *housesMinRadiusArray = (int*)calloc(housesSize, sizeof(int));;

   for ( int i=0;i<housesSize;i++ ){

      housesMinRadiusArray[i] = INT_MAX;

      for(int j=0;j<heatersSize;j++){
         if ( housesMinRadiusArray[i] > abs(houses[i]-heaters[j]) )
            housesMinRadiusArray[i] = abs(houses[i]-heaters[j]);
      }
   }


   int maxRadius = 0;

   for ( int i=0;i<housesSize;i++ ){
      if ( maxRadius < housesMinRadiusArray[i] ) maxRadius = housesMinRadiusArray[i];
   }


   return maxRadius;
}


int main(){


   int heaters[] = { 1, 4 };
   int heatersSize = sizeof(heaters)/sizeof(heaters[0]);

   int houses[]  = { 1, 2, 3, 4 };
   int housesSize = sizeof(houses)/sizeof(houses[0]);

   int radius = findRadius( houses, housesSize, heaters, heatersSize );

   printf("%d\n", radius);

   return 0;
}
