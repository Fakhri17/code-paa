#include <stdio.h>

// Function to calculate binary search using brute force
int binarySearchBruteForce(int arr[], int n, int x)
{
  int left = 0;
  int right = n - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    // Check if x is present at mid
    if (arr[mid] == x)
    {
      return mid;
    }
    // If x greater, ignore left half
    if (arr[mid] < x)
    {
      left = mid + 1;
    }
    // If x is smaller, ignore right half
    else
    {
      right = mid - 1;
    }
  }
  // If we reach here, then element was not present
  return -1;
}

int main()
{
  int arr[] = {2, 3, 4, 10, 40};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 10;
  int result = binarySearchBruteForce(arr, n, x);
  if (result == -1)
  {
    printf("Element is not present in array");
  }
  else
  {
    printf("Element %d is present at index %d", x, result);
  }
}