#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack{
  unsigned long int capacity;
  long int top;
  int *stackPtr;
};

struct Stack* createStack(unsigned long int capacity, size_t sizePerItem)
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

void push(struct Stack *stack, int item)
{
  if (stack->top == stack->capacity - 1){
    printf("stack overflow!\n");
    exit(0);
  }
  else{
    stack->stackPtr[++stack->top] = item;
  }
}

//int pop(struct Stack *stack, int line)
//{
//  if (stack->top == - 1){
//    printf("stack underflow at %d!\n", line);
//    exit(0);
//  }
//  else{
//    return stack->stackPtr[stack->top--];
//  }
//}

//int peek(struct Stack *stack, long int line)
//{
//  if (stack->top == - 1){
//    return '\0';
//  }
//  else{
//    return stack->stackPtr[stack->top];
//  }
//}


void displayStack(struct Stack *stack)
{
  if (stack->top == - 1){
    printf("stack is empty!\n");
    exit(0);
  }
  else{
      for(long int i=stack->top; i > -1; i--){
        printf("%d", stack->stackPtr[i]);
      }
      printf("\n");
  }
}


int displayStackInverse(struct Stack *stack)
{
  int output = 0;
  int base   = 1;

  if (stack->top == - 1){
    printf("stack is empty!\n");
    exit(0);
  }
  else{
      for(long int i=stack->top; i > -1; i--){

        output += base*stack->stackPtr[i];

        base *= 10;

      }
  }

  return output;
}




int reverse( int input )
{

  unsigned long int capacity = 0;

  int positive = 0;

  if (input > 0){
    positive =  1;
  }
  else if (input < 0){
    positive = -1;
    input = -input;
  }
  else{
    positive =  0;
    return 0;
  }

  int input2 = input;
  int digit;

  while(input >= 1){
    digit = input % 10;
    input -= digit;
    input /= 10;
    capacity++;
  }

  struct Stack *stack = createStack(capacity, sizeof(int));

  input = input2;

  while(input >= 1){
    digit = input % 10;
    input -= digit;
    input /= 10;
    push (stack, digit);
  }


  int output = displayStackInverse(stack);

  freeStack( stack );

  if (positive == -1) output = -output;

  return output;

}

int main()
{

  int input = -5432100;

  printf("%d\n", reverse(input));

  return 0;
}
