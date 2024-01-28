#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int array[], int n);

int main()
{
  int array[] = {6, 2, -2, 10, 1, 7};
  int n = sizeof(array) / sizeof(array[0]);

  bubble_sort(array, n);

  return 0;
}

void bubble_sort(int array[], int n)
{
  int i, j;
  bool flag;
  for (i = 0; i < n - 1; i++)
  {
    flag = false;
    for (j = 0; j < n - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        flag = true;
      }
    }
    if (flag == false)
    {
      break;
    }
  }
  printf("Sorted array is: ");
  for (j = 0; j < n; j++)
  {
    printf("%d ", array[j]);
  }
  printf("\n");
}
