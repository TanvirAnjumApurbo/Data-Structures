#include <stdio.h>

int linearSearch(int array[], int size, int data);

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

  int index = linearSearch(array, size, data);
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

int linearSearch(int array[], int size, int data)
{
  for (int index = 0; index < size; index++)
  {
    if (array[index] == data)
    {
      return index;
    }
  }
  return -1;
}
