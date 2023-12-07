// Binary Search
#include <stdio.h>

int binarySearch(int data);
int A[100], n, i, data, index;

int main()
{
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  printf("Enter the element to be searched: ");
  scanf("%d", &data);
  index = binarySearch(data);
  if (index == -1)
  {
    printf("Element not found\n");
  }
  else
  {
    printf("Element found at index %d\n", index);
  }
  return 0;
}

int binarySearch(int data)
{
  int low = 0, high = n - 1, mid;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (data == A[mid])
    {
      return mid;
    }
    else if (data < A[mid])
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return -1;
}