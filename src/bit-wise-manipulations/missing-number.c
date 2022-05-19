// x^y = y^x
// x^x = 0
// 0^x = x

// If X = a1^a2^...^an and Y = a1^a2^...^a_{n-1}
// then X^Y = an

int missingNumber(int* nums, int numsSize){

    int x = 0;
    int y = numsSize;

    for( int i=0;i<numsSize;i++ ){
        x ^= nums[i];
        y ^= i;
    }

    return x^y;
}
