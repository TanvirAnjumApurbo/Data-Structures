#include <stdio.h>

void insertion_sort(int arr[], int n);

int main()
{
  int arr[] = {6, 2, -2, 10, 1, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  insertion_sort(arr, n);

  return 0;
}

void insertion_sort(int arr[], int n)
{
  int i, j, temp;
  for (i = 1; i < n; i++)
  {
    temp = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > temp)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
  printf("Sorted array is: ");
  for (j = 0; j < n; j++)
  {
    printf("%d ", arr[j]);
  }
  printf("\n");
}