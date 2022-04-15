// TITLE: reverse integer
// TAG: array, stack, reverse, integer
// LEVEL: easy

// https://www.geeksforgeeks.org/reverse-digits-integer-overflow-handled
// https://leetcode.com/problems/reverse-integer/


// Given a signed 32-bit integer x, return x with its digits reversed.
// If reversing x causes the value to go outside the signed 32-bit
// integer range [-2^31, 2^31 - 1], then return 0.



#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>
#include<limits.h>


//#define DEBUG

bool checkInt32Overflow(int32_t a, int32_t b, int operation, int line)
{
  bool overflow = false;

  if (operation == '+')
  {
     if ( ( b > 0 ) && ( a > INT32_MAX-b ) ) overflow = true;
     if ( ( b < 0 ) && ( a < INT32_MIN-b ) ) overflow = true;

  }
  else if (operation == '*')
  {
     if (  b != 0 && a > INT32_MAX / b  )    overflow = true;
     if (  b != 0 && a < INT32_MIN / b  )    overflow = true;

  }
  else
  {
     printf("something wrong!\n");
     exit(0);
  }

# ifdef DEBUG
  if (overflow) printf("a=%d, b=%d, line=%d\n", a, b, line);
# endif

  return overflow;
}


int32_t reverse(int32_t num)
{
    // Handling negative numbers
    bool negativeFlag = false;

    if (num < 0)
    {
        negativeFlag = true;
        num = -num ;
    }

    int32_t prev_rev_num = 0, rev_num = 0;

    while (num != 0)
    {
        int32_t curr_digit = num%10;


        if (   checkInt32Overflow( rev_num   ,         10, '*', __LINE__ )
            || checkInt32Overflow( rev_num*10, curr_digit, '+', __LINE__ ) )
        return 0;


        rev_num = (rev_num*10) + curr_digit;

        prev_rev_num = rev_num;
        num = num/10;
    }

    return (negativeFlag == true)? -rev_num : rev_num;
}

int main()
{

  int32_t input = INT32_MAX;

# ifdef DEBUG
  printf("INT32_MAX=%+d\n", INT32_MAX);
  printf("input    =%+d\n", input);
  printf("INT32_MIN=%+d\n", INT32_MIN);
# endif

  printf("%d\n", reverse(input));


  return 0;
}
