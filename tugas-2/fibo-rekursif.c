#include <stdio.h>

// Function to calculate fibonacci using recursion
int fibonacciRecursive(int n)
{
  // ternary operator ( base case & recursive case)
  return (n <= 1) ? n : fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main()
{
  int n;
  printf("Masukkan bilangan bulat positif: ");
  scanf("%d", &n);
  int result = fibonacciRecursive(n);
  printf("Fibonacci dari %d adalah %d", n, result);
  return 0;
}