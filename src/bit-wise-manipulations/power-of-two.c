bool isPowerOfTwo(int n){

    // negative numbers are not power of 2
    if ( (n >>31) & 1 ) return false;

    // zero is not power of 2
    if ( n == 0 ) return false;

    if  (n&(n-1))  return false;

    else return true;
}
