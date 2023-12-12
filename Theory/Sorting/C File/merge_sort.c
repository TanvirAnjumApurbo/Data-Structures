#include <stdio.h>

void merge(int array[], int left, int middle, int right);
void merge_sort(int array[], int left, int right);

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
  
  merge_sort(array, 0, array_length - 1);
  
  printf("The sorted array is: ");
  for (index = 0; index < array_length; index++)
  {
    printf("%d ", array[index]);
  }
  printf("\n");
  return 0;
}

void merge(int array[], int left, int middle, int right)
{
  int left_size = middle - left + 1;
  int right_size = right - middle;

  int Left[left_size], Right[right_size];
  int i, j, k;

  // Copy data to temp arrays Left[] and Right[]
  for (i = 0; i < left_size; i++)
  {
    Left[i] = array[left + i];
  }
  for (j = 0; j < right_size; j++)
  {
    Right[j] = array[middle + 1 + j];
  }

  // Merge the temp arrays back into array[left...right]
  i = 0;
  j = 0;
  k = left;

  while (i < left_size && j < right_size)
  {
    if (Left[i] <= Right[j])
    {
      array[k] = Left[i];
      i++;
    }
    else
    {
      array[k] = Right[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of Left[], if any
  while (i < left_size)
  {
    array[k] = Left[i];
    i++;
    k++;
  }

  // Copy the remaining elements of Right[], if any
  while (j < right_size)
  {
    array[k] = Right[j];
    j++;
    k++;
  }
}

void merge_sort(int array[], int left, int right)
{
  if (left < right)
  {
    int middle = left + (right - left) / 2;

    // Sort first and second halves
    merge_sort(array, left, middle);
    merge_sort(array, middle + 1, right);

    // Merge the sorted halves
    merge(array, left, middle, right);
  }
}
