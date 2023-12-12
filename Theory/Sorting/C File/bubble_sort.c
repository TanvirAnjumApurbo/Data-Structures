#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int array[], int array_length);
void swap(int *a, int *b);

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
  bubble_sort(array, array_length);
  return 0;
}

void bubble_sort(int array[], int array_length)
{
  int pass, index;
  bool flag;
  for (pass = 0; pass < array_length - 1; pass++)
  {
    flag = false;
    for (index = 0; index < array_length - pass - 1; index++)
    {
      if (array[index] > array[index + 1])
      {
        swap(&array[index], &array[index + 1]);
        flag = true;
      }
    }
    if (flag == false)
    {
      break;
    }
  }
  printf("The sorted array is: ");
  for (index = 0; index < array_length; index++)
  {
    printf("%d ", array[index]);
  }
  printf("\n");
}

void swap(int *a, int *b)
{
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}