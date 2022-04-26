// TITLE: Spiral Matrix II
// LEVEL: medium
// TAG: array, loop-invariant

#include<stdio.h>
#include<stdlib.h>


// ----------
// | 1| 2| 3|
// ----------
// | 8| 9| 4|
// ----------
// | 7| 6| 5|
// ----------


typedef int mytype;

int **calloc_2d_array(size_t nr, size_t nc){

   int **array = NULL;

   array = (int**)calloc(nr, sizeof(mytype*));

   array[0] = (int*)calloc(nr*nc, sizeof(mytype));

   for (int i=1;i<nr;i++) array[i] = array[0] + i*nc;

   return array;

}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
   *returnSize = n;


   int **array = calloc_2d_array(n, n);

   int number = 1;
   int numLoop = 0;
   int counter = 0;
   int offset = 0;

   numLoop = ((n&1) == 0) ? n/2 : (n-1)/2;




   for( int loop=0;loop<numLoop;loop++ ){
      // upper side
      for (int k=offset;k<n-1-offset;k++){
         array[offset][k] = ++counter;
      }

      // right side
      for (int i=offset;i<n-1-offset;i++){
         array[i][n-1-offset] = ++counter;
      }
      // lower side
      for (int k=n-1-offset;k>offset;k--){
         array[n-1-offset][k] = ++counter;
      }

      // left side
      for (int i=n-1-offset;i>offset;i--){
         array[i][offset] = ++counter;
      }

      offset++;
   }

   if (n&1 == 1){
      array[(n-1)/2][(n-1)/2] = ++counter;
   }

   *returnColumnSizes = malloc(sizeof(void*)*n);
   for ( int i=0;i<n;i++ )  (*returnColumnSizes)[i] = n;

   return array;
}



int main(){

   int n = 10;

   int returnSize;

   int *returnColumnSizes = NULL;

   int **array = generateMatrix(n, &returnSize, &returnColumnSizes);

   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         printf("%2d ", array[i][j]);
      }
      printf("\n");
   }

   return 0;
}
