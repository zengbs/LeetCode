#include<stdio.h>

int foo(int a){

   // check stack grows direction
   printf("%p\n", &a);

   return foo(a-1);
}


int main(){
   printf("%d\n", foo(100));
   return 0;
}
