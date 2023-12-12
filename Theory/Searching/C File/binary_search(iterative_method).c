#include <stdio.h>

int binarySearch(int array[], int size, int data);

int main()
{
  int size, data;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int array[size];
  printf("Enter the elements of the array:\n");
  for (int index = 0; index < size; index++)
  {
    scanf("%d", &array[index]);
  }

  printf("Enter the data to search: ");
  scanf("%d", &data);

  int index = binarySearch(array, size, data);
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

int binarySearch(int array[], int size, int data)
{
  int low = 0, high = size - 1, mid;
  while (low <= high)
  {
    mid = low + (high - low) / 2;
    if (data == array[mid])
    {
      return mid;
    }
    else if (data < array[mid])
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