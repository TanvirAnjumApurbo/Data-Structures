#include <stdio.h>

int binarySearch(int array[], int low, int high, int data);

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

  int index = binarySearch(array, 0, size - 1, data);
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

int binarySearch(int array[], int low, int high, int data)
{
  if (high >= low)
  {
    int mid = low + (high - low) / 2;
    if (array[mid] == data)
    {
      return mid;
    }
    else if (array[mid] > data)
    {
      return binarySearch(array, low, mid - 1, data);
    }
    else
    {
      return binarySearch(array, mid + 1, high, data);
    }
  }
  return -1;
}