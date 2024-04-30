#include <stdio.h>

// Function to calculate fibonacci using brute force
int fibonacciBruteForce(int n)
{

  // Base case
  if (n <= 1)
  {
    return n;
  }
  // Bruteforce case
  else{
    int a = 0;
    int b = 1;
    int temp;
    for (int i = 2; i <= n; i++)
    {
      temp = a + b;
      a = b;
      b = temp;
    }
    return b;
  }
}

int main()
{
  int n;
  printf("Masukkan bilangan bulat positif: ");
  scanf("%d", &n);
  int result = fibonacciBruteForce(n);
  printf("Fibonacci dari %d adalah %d", n, result);
  return 0;
}