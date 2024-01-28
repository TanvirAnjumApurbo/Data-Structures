#include <stdio.h>

int main()
{
  int a[] = {8, 4, 4, 3, 101, -1, 2};
  int i, temp, j, n = 7;
  for (i = 1; i < n; i++)
  {
    temp = a[i];
    for (j = i - 1; j >= 0; j--)
    {
      if (a[j] > temp)
      {
        a[j + 1] = a[j];
      }
      else
      {
        break;
      }
    }
    a[j + 1] = temp;
  }
  printf("sorted array\n\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n\n");
  return 0;
}