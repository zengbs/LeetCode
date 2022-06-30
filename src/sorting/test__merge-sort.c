




void merge( int *arr, int l, int m, int r )
{
   int right[m-l+2]; // l..m,m+1
   int  left[r-m+1]; // m+1..r,r+1

   for ( int i=0;i<m-l+1;i++ ) right[i] = arr[  l+i];
   for ( int i=0;i<r-m  ;i++ )  left[i] = arr[m+1+i];

   right[m-l+1] = INT_MAX;
    left[r-m] = INT_MAX;

   int index_r = 0;
   int index_l = 0;

   for (int i=0;i<=r-l;i++){

      if( right[index_r] > left[index_l] ){
         arr[l+i] = left[index_l++];
      }
      else{
         arr[l+i] = right[index_r++];
      }
   }

}


void mergeSort( int *arr, int l, int r )
{

   if ( r <= l ) return;

   int m = l+(r-l)/2;

   mergeSort( arr, l  , m );
   mergeSort( arr, m+1, r );

   merge(arr, l, m, r);

}
