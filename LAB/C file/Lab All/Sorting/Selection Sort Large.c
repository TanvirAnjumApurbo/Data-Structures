#include <stdio.h>
#include <math.h>

void selection_sort(int array[], int n);

int main()
{
  int array[] = {6, 2, -2, 10, 1, 7};
  int n = sizeof(array) / sizeof(array[0]);

  selection_sort(array, n);

  return 0;
}

void selection_sort(int array[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    double largest = -INFINITY;
    int idx_at_largest = -1;
    for (j = 0; j < n - i; j++)
    {
      if (array[j] > largest)
      {
        largest = array[j];
        idx_at_largest = j;
      }
    }
    int temp = array[idx_at_largest];
    array[idx_at_largest] = array[n - i - 1];
    array[n - i - 1] = temp;
  }
  printf("Sorted array is: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}