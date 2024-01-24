#include <stdio.h>
#include <math.h>

void swap(int *a, int *b);
void selection_sort(int arr[], int n);

int main()
{
  int i, n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  selection_sort(arr, n);
  return 0;
}

void selection_sort(int arr[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    double largest = -INFINITY;
    int idx_at_largest = -1;
    for (j = 0; j < n - i; j++)
    {
      if (arr[j] > largest)
      {
        largest = arr[j];
        idx_at_largest = j;
      }
    }
    swap(&arr[n - 1 - i], &arr[idx_at_largest]);
  }

  printf("sorted array is: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}

void swap(int *a, int *b)
{
  if (a != b)
  {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
  }
}