#include <stdio.h>

// Function to calculate binary search using recursion
int binarySearchRecursive(int arr[], int left, int right, int x)
{
  if (right >= left)
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
      return binarySearchRecursive(arr, mid + 1, right, x);
    }
    // If x is smaller, ignore right half
    else
    {
      return binarySearchRecursive(arr, left, mid - 1, x);
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
  int result = binarySearchRecursive(arr, 0, n - 1, x);
  if (result == -1)
  {
    printf("Element is not present in array");
  }
  else
  {
    printf("Element %d is present at index %d", x, result);
  }
}