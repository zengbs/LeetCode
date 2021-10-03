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


struct Stack{
  int32_t capacity;
  int32_t top;
  int32_t *stackPtr;
};

struct Stack* createStack(int32_t capacity, size_t sizePerItem)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->stackPtr = malloc((size_t)(stack->capacity) * sizePerItem);
    return stack;
}

void freeStack(struct Stack *stack)
{
  free(stack->stackPtr);
  free(stack);
}

void push(struct Stack *stack, int32_t item)
{
  if (stack->top == stack->capacity - 1){
    printf("stack overflow!\n");
    exit(0);
  }
  else{
    stack->stackPtr[++stack->top] = item;
  }
}



int32_t displayStackInverse(struct Stack *stack)
{
  int32_t output = 0;
  int32_t base   = 1;

  if (stack->top == - 1){
    printf("stack is empty!\n");
    exit(0);
  }
  else{

      for(int32_t i=stack->top; i > -1; i--){

        if ( checkInt32Overflow( base, stack->stackPtr[i], '*', __LINE__ ) )        return 0;
        if ( checkInt32Overflow( base*stack->stackPtr[i], output, '+', __LINE__ ) ) return 0;

        output += base*stack->stackPtr[i];

#       ifdef DEBUG
        printf("i=%d, stack->top=%d, output=%d\n", i, stack->top, output);
#       endif

// if i == 0 and input == -2147483412 then code will crash
        if ( i != 0 && checkInt32Overflow( base, 10, '*', __LINE__ ) )  return 0;

        base *= 10;

      }
  }

  return output;
}




int32_t reverse( int32_t input )
{

  int32_t capacity = 0;

  int32_t positive = 0;

  if (input > INT32_MAX-1 || input < INT32_MIN){
    return 0;
  }

//if input == INT32_MIN, input = -input will overflow at the line 127
  else if (input == INT32_MIN){
    return 0;
  }
  else if (input > 0){
    positive =  1;
  }
  else if (input < 0){
    positive = -1;
    input = -input;
  }
  else if (input == 0){
    positive =  0;
    return 0;
  }

  int32_t input2 = input;
  int32_t digit;


  while(input >= 1){
    digit = input % 10;
    input -= digit;
    input /= 10;
    capacity++;
  }


  struct Stack *stack = createStack(capacity, sizeof(int32_t));

  input = input2;

  while(input >= 1){
    digit = input % 10;
    input -= digit;
    input /= 10;
    push (stack, digit);
  }


  int32_t output = displayStackInverse(stack);

  freeStack( stack );

  if (positive == -1) output = -output;


  return output;

}

int main()
{

  int32_t input = -2147483412;

# ifdef DEBUG
  printf("INT32_MAX=%+d\n", INT32_MAX);
  printf("input    =%+d\n", input);
  printf("INT32_MIN=%+d\n", INT32_MIN);
# endif

  printf("%d\n", reverse(input));


  return 0;
}
