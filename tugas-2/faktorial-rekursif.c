#include <stdio.h>

// Function to calculate factorial using recursion
int factorialRecursive(int n)
{
  // ternary operator ( base case & recursive case)
  return (n == 0) ? 1 : n * factorialRecursive(n - 1);
}

int main()
{
  int n;
  printf("Masukkan bilangan bulat positif: ");
  scanf("%d", &n);
  int result = factorialRecursive(n);
  printf("Faktorial dari %d adalah %d", n, result);
  return 0;
}