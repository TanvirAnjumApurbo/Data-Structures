#include <stdio.h>

void insertion_sort(int array[], int array_length);
void swap(int *a, int *b);

int main()
{
  int array_length, index;
  printf("Enter the length of the array: ");
  scanf("%d", &array_length);
  int array[array_length];
  printf("Enter the elements of the array: ");
  for (index = 0; index < array_length; index++)
  {
    scanf("%d", &array[index]);
  }
  insertion_sort(array, array_length);
  return 0;
}

void insertion_sort(int array[], int array_length)
{
  int index, pass, min_index;
  for (pass = 0; pass < array_length - 1; pass++)
  {
    min_index = pass;
    for (index = pass + 1; index < array_length; index++)
    {
      if (array[index] < array[min_index])
      {
        min_index = index;
      }
    }
    if (min_index != pass)
    {
      swap(&array[pass], &array[min_index]);
    }
  }
  printf("The sorted array is: ");
  for (index = 0; index < array_length; index++)
  {
    printf("%d ", array[index]);
  }
  printf("\n");
}

void swap(int *a, int *b)
{
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}