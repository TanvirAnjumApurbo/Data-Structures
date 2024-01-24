#include <stdio.h>
void traversal(int array[]);
void insertion(int array[]);
void deletion(int array[]);
int new_array[6];

int main()
{
  int array[5], i;
  printf("Enter the elements of the array: \n");
  for (i = 0; i < 5; i++)
  {
    scanf("%d", &array[i]);
  }
  traversal(array);
  insertion(array);
  deletion(array);
  return 0;
}

void traversal(int array[])
{
  int i;
  printf("Array: ");
  for (i = 0; i < 5; i++)
  {
    printf("%d ", array[i]);
  }
}

void insertion(int array[])
{
  int v, pos, i, j;
  printf("\nEnter the value to be inserted: ");
  scanf("%d", &v);
  printf("Enter the position to be inserted: ");
  scanf("%d", &pos);
  for (i = 0; i < pos; i++)
  {
    new_array[i] = array[i];
  }
  new_array[pos] = v;
  for (j = pos + 1; j < 6; j++)
  {
    new_array[j] = array[j - 1];
  }

  printf("New Array: ");
  for (i = 0; i < 6; i++)
  {
    printf("%d ", new_array[i]);
  }
  return;
}

void deletion(int array[])
{
  int pos, i, j;
  printf("\nEnter the position to be deleted: ");
  scanf("%d", &pos);

  for (i = 0; i < pos - 1; i++)
  {
    new_array[i] = array[i];
  }
  for (j = pos; j < 5 - 1; j++)
  {
    new_array[j] = array[j + 1];
  }
  printf("New Array after deletion: ");
  for (i = 0; i < 4; i++)
  {
    printf("%d ", new_array[i]);
  }
  return;
}