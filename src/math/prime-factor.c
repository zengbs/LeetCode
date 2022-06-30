#include <stdio.h>

void primeFactors(int n)
{
  int c = 2;

  while (n > 1) {

    if (n % c == 0) {
      printf("%d ", c);
      n /= c;
    }
    else
      c++;
  }

  printf("\n");
}

/* Driver code */
int main()
{
  int n = 18;
  primeFactors(n);
  return 0;
}
