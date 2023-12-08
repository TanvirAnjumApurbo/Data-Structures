#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int);
int dequeue();
int peek();
void print();
int isFull();
int isEmpty();

int main()
{
  int choice, data;
  while (1)
  {
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Print the first element\n");
    printf("4. Print all elements\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the element to be added in the queue: ");
      scanf("%d", &data);
      enqueue(data);
      printf("Element is added in the queue successfully\n");
      break;
    case 2:
      data = dequeue();
      printf("Deleted element is %d\n", data);
      break;
    case 3:
      printf("The first element of the queue is %d\n", peek());
      break;
    case 4:
      print();
      break;
    case 5:
      exit(1);
    default:
      printf("Invalid choice\n");
    }
  }
}

void enqueue(int data)
{
  if (isFull())
  {
    printf("Queue Overflow\n");
    exit(1);
  }
  if (front == -1)
  {
    front = 0;
  }
  rear = rear + 1;
  queue[rear] = data;
}

int dequeue()
{
  int data;
  if (isEmpty())
  {
    printf("Queue Underflow\n");
    exit(1);
  }
  data = queue[front];
  {
    front++;
  }
  return data;
}

int isEmpty()
{
  if (front == -1 || front == rear + 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isFull()
{
  if (rear == MAX - 1)
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
    printf("Queue Underflow\n");
    exit(1);
  }
  return queue[front];
}

void print()
{
  int i;
  if (isEmpty())
  {
    printf("Queue Underflow\n");
    exit(1);
  }
  printf("Queue: ");
  for (i = front; i <= rear; i++)
  {
    printf("%d ", queue[i]);
  }
  printf("\n");
}