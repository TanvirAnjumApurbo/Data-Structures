#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int isFull();        // O(1)
int isEmpty();       // O(1)
void push(int data); // O(1)
int pop();           // O(1)
int peek();          // O(1)
void print();

int stack_arr[MAX];
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

int isFull()
{
  if (top == MAX - 1)
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

void push(int data)
{
  if (isFull())
  {
    printf("Stack Overflow\n");
    /* When overflow there is a only way to extend the size is create a larger array and copy the elements to the new array. Cost: O(n); where n = Number of elements in the stack.*/
    return;
  }
  else
  {
    top = top + 1;
    stack_arr[top] = data;
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
    int value = stack_arr[top];
    top = top - 1;
    return value;
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
    return stack_arr[top];
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
      printf("%d\n", stack_arr[i]);
    printf("\n");
  }
}
