#include <stdio.h>

void selection_sort(int arr[], int n);
void swap(int *a, int *b);

int main()
{
  int n, i;
  printf("Enter the number of elements: \n");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements: \n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  selection_sort(arr, n);
  return 0;
}

void selection_sort(int arr[], int n)
{
  int i, j, min;
  for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i + 1; j < n; j++)
    {
      if (arr[min] > arr[j])
        min = j;

      if (min != i)
        swap(&arr[i], &arr[min]);
    }
  }
  printf("Sorted array is: ");
  for (i = 0; i < n; i++)
    printf("%d  ", arr[i]);
}

void swap(int *a, int *b)
{
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}