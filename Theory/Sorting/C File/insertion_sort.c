#include <stdio.h>

void insertion_sort(int array[], int array_length);

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
  int unsorted_array_index, sorted_array_index, temp;
  for (unsorted_array_index = 1; unsorted_array_index < array_length; unsorted_array_index++)
  {
    temp = array[unsorted_array_index];
    sorted_array_index = unsorted_array_index - 1;
    while (sorted_array_index >= 0 && array[sorted_array_index] > temp)
    {
      array[sorted_array_index + 1] = array[sorted_array_index];
      sorted_array_index--;
    }
    array[sorted_array_index + 1] = temp;
  }
  printf("The sorted array is: ");
  for (sorted_array_index = 0; sorted_array_index < array_length; sorted_array_index++)
  {
    printf("%d ", array[sorted_array_index]);
  }
  printf("\n");
}