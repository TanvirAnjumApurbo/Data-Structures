#include <stdio.h>

void insertion_sort(int array[], int n);

int main()
{
  int array[] = {6, 2, -2, 10, 1, 7};
  int n = sizeof(array) / sizeof(array[0]);

  insertion_sort(array, n);

  return 0;
}

void insertion_sort(int array[], int n)
{
  int i, j, temp;
  for (i = 1; i < n; i++)
  {
    temp = array[i];
    j = i - 1;
    while (j >= 0 && array[j] > temp)
    {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = temp;
  }
  printf("Sorted array is: ");
  for (j = 0; j < n; j++)
  {
    printf("%d ", array[j]);
  }
  printf("\n");
}