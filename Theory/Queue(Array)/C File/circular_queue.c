#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int circular_queue[MAX];
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
  if (rear == MAX - 1)
  {
    rear = 0;
  }
  else
  {
    rear = rear + 1;
  }
  circular_queue[rear] = data;
}

int dequeue()
{
  int data;
  if (isEmpty())
  {
    printf("Queue Underflow\n");
    exit(1);
  }
  data = circular_queue[front];
  if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else if (front == MAX - 1)
  {
    front = 0;
  }
  else
    front = front + 1;
  return data;
}

int isEmpty()
{
  if (front == -1)
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
  if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
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
  return circular_queue[front];
}

void print()
{
  int temp;
  if (isEmpty())
  {
    printf("Queue Underflow\n");
    exit(1);
  }
  temp = front;
  if (front <= rear)
  {
    while (temp <= rear)
    {
      printf("%d ", circular_queue[temp]);
      temp++;
    }
  }
  else
  {
    while (temp <= MAX - 1)
    {
      printf("%d ", circular_queue[temp]);
      temp++;
    }
    temp = 0;
    while (temp <= rear)
    {
      printf("%d ", circular_queue[temp]);
      temp++;
    }
  }
  printf("\n");
}