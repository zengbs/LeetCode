#include<stdio.h>
#include<stdlib.h>

typedef int32_t mytype;

mytype** calloc_2d_array(size_t nc, size_t nr)
{
  mytype **array;

  size_t i;

  array = (mytype**)calloc(nr,sizeof(mytype*));

  array[0] = (mytype*)calloc(nr*nc,sizeof(mytype));

  for(i=1; i<nr; i++)  array[i] = (array[0] + i*nc);

  return array;
}

mytype **calloc_2d( size_t nc, size_t nr, size_t size )
{

   mytype **array = NULL;

   array = (mytype**)calloc(nr, sizeof(mytype*));

   array[0] = (mytype*)calloc(nr*nc, size);

   for (size_t i=1;i<nr;i++)
      array[i] = (mytype*)((unsigned char*)array[0] + i*nc*size);

   return array;
}
// array[i][j]


mytype free_2d( mytype **array ){
   free(&array[0][0]);
   free(&array[0]);
}

//// pointer to a 2D array
//int (*array)[NCOL][NROW] = (int*)malloc(sizeof(*array));
//// (*array)[i][j]
//free(array);
//
//
//// pointer to an 1D array of `NCOL` integers
//int (*array)[NCOL] = (int(*)[NCOL])malloc(sizeof(*array)*NROW);
//// array[i][j]
//free(array);
//
//// pointer to the first element in 2D array
//int *array = (int*)maloc(nc*nr*sizeof(int));
//// *(array+i*nc+j)
//free(array);
//
//
//void **calloc_2d(size_t nr, size_t nc, size_t size)
//{
//
//   void **array = NULL;
//
//   *array = calloc(nc, size);
//
//   for (int i=0;i<nr;i++)
//      array[i] = calloc(nr, size);
//
//   return array;
//}
//
//// array[i][j]



int main(){



   int nr = 2;
   int nc = 3;

   mytype **array = (mytype**)calloc_2d( nc, nr, sizeof(mytype) );


   for ( int i=0;i<nr;i++ ){
      for ( int j=0;j<nc;j++ ){
         array[i][j] = i*nc+j;
      }
   }


   for ( int i=0;i<nr;i++ ){
      for ( int j=0;j<nc;j++ ){
         printf("%d ", array[i][j]);
      }
      printf("\n");
   }

   free_2d(array);

   return 0;
}
