// Linear Search
#include <stdio.h>

int A[100], n, i, data, index;
int linearSearch(int data);

int main()
{
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  printf("Enter the element to be searched: ");
  scanf("%d", &data);
  index = linearSearch(data);
  if (index == -1)
  {
    printf("Element not found\n");
  }
  else
  {
    printf("Element found at index %d\n", index);
  }
  return 0;
}

int linearSearch(int data)
{
  for (i = 0; i < n; i++)
  {
    if (A[i] == data)
    {
      return i;
    }
  }
  return -1;
}
