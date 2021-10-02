#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack{
  long int capacity;
  long int top;
  char *stackPtr;
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

void push(struct Stack *stack, char item)
{
  if (stack->top == stack->capacity - 1){
    printf("stack overflow!\n");
    exit(0);
  }
  else{
    stack->stackPtr[++stack->top] = item;
  }
}

char pop(struct Stack *stack, int line)
{
  if (stack->top == - 1){
    printf("stack underflow at %d!\n", line);
    exit(0);
  }
  else{
    return stack->stackPtr[stack->top--];
  }
}

char peek(struct Stack *stack, long int line)
{
  if (stack->top == - 1){
    return '\0';
  }
  else{
    return stack->stackPtr[stack->top];
  }
}
void displayStack(struct Stack *stack)
{
  if (stack->top == - 1){
    printf("stack is empty!\n");
    exit(0);
  }
  else{
      for(long int i=stack->top; i > -1; i--){
        printf("%c", stack->stackPtr[i]);
      }
      printf("\n");
  }
}




int reverse( int input )
{
  int output;


  return output;
}

int main()
{



  return 0;
}
