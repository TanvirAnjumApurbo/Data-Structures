#include <stdio.h>
void push(int x);
void pop();
int isFull();
int isEmpty();
int Top();
void traversal();

int stack[5], top = -1;

void main()
{
  while (1)
  {
    int choice, x;
    printf("Enter choice (1.push 2.pop 3.Top 4.exit): ");
    scanf("%d", &choice);
    if (choice == 1)
    {
      printf("Enter new data: ");
      scanf("%d", &x);
      push(x);
      traversal();
    }
    else if (choice == 2)
    {
      pop();
      traversal();
    }
    else if (choice == 3)
    {
      printf("Top: %d\n", Top());
      traversal();
    }
    else if (choice == 4)
    {
      break;
    }
    else
    {
      printf("Invalid choice\n");
    }
  }
  return;
}

void push(int x)
{
  if (isFull())
    printf("Stack Overflow");
  else
  {
    top = top + 1;
    stack[top] = x;
  }
}

void pop()
{
  if (isEmpty())
    printf("Stack Underflow");
  else
  {
    top = top - 1;
  }
}

int isFull()
{
  if (top == 4)
    return 1;
  else
    return 0;
}

int isEmpty()
{
  if (top == -1)
    return 1;
  else
    return 0;
}

int Top()
{
  return stack[top];
}

void traversal()
{
  int i;
  printf("The stack: ");
  for (i = 0; i <= top; i++)
  {
    printf("%d ", stack[i]);
  }
  printf("\n");
}