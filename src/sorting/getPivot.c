# define MEDIAN_OF_THREE

int getPivot( int *arr, int l0, int r0 ){

#  ifdef MEDIAN_OF_THREE
   int a[3] = {arr[l0], arr[l0+(r0-l0)/2], arr[r0]};


    if      (!((a[1] < a[0]) ^ (a[0] < a[2]))) return a[0];
    else if (!((a[0] < a[1]) ^ (a[1] < a[2]))) return a[1];
    else                                       return a[2];
#  endif

}
