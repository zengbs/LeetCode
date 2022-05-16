
# define MEDIAN_OF_THREE

int getPivot( int *arr, int l0, int r0 ){


#  ifdef MEDIAN_OF_THREE
   int a[3] = {arr[l0], arr[l0+(r0-l0)/2], arr[r0]};

   int maxIdx;

   maxIdx = ( a[0] > a[1]      ) ? 0 : 1 ;
   maxIdx = ( a[2] > a[maxIdx] ) ? 2 : maxIdx ;


   switch (maxIdx){
      case 0:
         if ( a[2] > a[1]) return a[2]; else return a[1];
      break;

      case 1:
         if ( a[2] > a[0]) return a[2]; else return a[0];
      break;

      case 2:
         if ( a[0] > a[1]) return a[0]; else return a[1];
      break;
   }
#  endif

}
