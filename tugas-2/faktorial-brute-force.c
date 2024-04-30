#include <stdio.h>

// Function to calculate factorial using brute force
int factorialBruteForce(int n)
{
  int result;
  // Base case
  if (n == 0)
  {
    return 1;
  }
  // Bruteforce case
  else
  {
    result = 1;
    for (int i = 1; i <= n; i++)
    {
      result *= i;
    }
    return result;
  }
}

int main()
{
  int n;
  printf("Masukkan bilangan bulat positif: ");
  scanf("%d", &n);
  int result = factorialBruteForce(n);
  printf("Faktorial dari %d adalah %d", n, result);
  return 0;
}