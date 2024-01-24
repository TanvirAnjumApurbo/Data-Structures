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
  int pass, i;
  bool flag;
  for (pass = 0; pass < n - 1; pass++)
  {
    flag = false;
    for (i = 0; i < n - pass - 1; i++)
    {
      if (array[i] > array[i + 1])
      {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        flag = true;
      }
    }
    if (flag == false)
    {
      break;
    }
  }
  printf("Sorted array is: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}
