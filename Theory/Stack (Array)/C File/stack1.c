#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int isFull();
int isEmpty();
void push(int data);
int pop();
int peek();
void print();

int stack_array[MAX];
int top = -1, data;

int main()
{
  int choice;
  while (1)
  {
    printf("\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print the  top element\n");
    printf("4. Print all the elements of the stack\n");
    printf("5. Exit\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the data to be pushed: ");
      scanf("%d", &data);
      push(data);
      break;
    case 2:
      data = pop();
      printf("The popped element is %d\n", data);
      break;
    case 3:
      printf("The top element is %d\n", peek());
      break;
    case 4:
      print();
      break;
    case 5:
      exit(1);
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}

void push(int data)
{
  if (isFull())
  {
    printf("Stack Overflow\n");
    return;
  }
  else
  {
    top = top + 1;
    stack_array[top] = data;
    printf("Pushed %d into the stack.\n", data);
  }
}

int pop()
{
  if (isEmpty())
  {
    printf("Stack Underflow\n");
    exit(1);
  }
  else
  {
    int value = stack_array[top];
    top = top - 1;
    return value;
  }
}

int isFull()
{
  if (top == MAX - 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isEmpty()
{
  if (top == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int peek()
{
  if (isEmpty())
  {
    printf("Stack Underflow\n");
    exit(1);
  }
  else
  {
    return stack_array[top];
  }
}

void print()
{
  if (isEmpty())
  {
    printf("Stack is empty\n");
    return;
  }
  else
  {
    printf("Stack elements :\n\n");
    for (int i = top; i >= 0; i--)
      printf("%d\n", stack_array[i]);
    printf("\n");
  }
}
