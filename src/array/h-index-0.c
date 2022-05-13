#include<stdio.h>

int hIndex(int* citations, int numsPaper){

   int maxHIdx = numsPaper;

   for ( int i=maxHIdx; i>=0; i-- ){

      int count = 0;

      for ( int paper=0; paper<numsPaper; paper++ ){
         if ( citations[paper] >= i ) count++;
      }

      if (count >= i ) return i;
   }

   return 0;
}


int main(){

   int citations[] = {3,0,6,1,5};

   int numsPaper = sizeof(citations)/sizeof(citations[0]);

   printf("%d\n", hIndex(citations, numsPaper));

}
