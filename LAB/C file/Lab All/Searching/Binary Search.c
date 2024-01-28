#include <stdio.h>

int BS(int A[], int data, int n);

int main()
{
  int A[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int n = sizeof(A) / sizeof(A[0]);
  int data;
  printf("Enter data: ");
  scanf("%d", &data);
  int index = BS(A, data, n);
  if (index == -1)
    printf("Data not found\n");
  else
    printf("%d found at index %d\n", data, index);
  return 0;
}

int BS(int A[], int data, int n)
{
  int l = 0, h = n - 1, mid;
  while (l <= h)
  {
    mid = (l + h) / 2;
    if (data == A[mid])
      return mid;
    else if (data < A[mid])
      h = mid - 1;
    else
      l = mid + 1;
  }
  return -1;
}