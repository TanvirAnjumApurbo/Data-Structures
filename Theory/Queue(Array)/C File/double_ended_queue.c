#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int deque[MAX];
int front = -1;
int rear = -1;

void enqueueFront(int);
void enqueueRear(int);
int dequeueFront();
int dequeueRear();
int peek();
int isFull();
int isEmpty();
void print();

int main()
{
  int choice, data;
  while (1)
  {
    printf("1. Insert at front\n");
    printf("2. Insert at rear\n");
    printf("3. Delete from front\n");
    printf("4. Delete from rear\n");
    printf("5. Print the first element\n");
    printf("6. Print all elements\n");
    printf("7. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the element to be added in the queue: ");
      scanf("%d", &data);
      enqueueFront(data);
      printf("Element is added in the queue successfully\n");
      break;
    case 2:
      printf("Enter the element to be added in the queue: ");
      scanf("%d", &data);
      enqueueRear(data);
      printf("Element is added in the queue successfully\n");
      break;
    case 3:
      data = dequeueFront();
      printf("Deleted element is %d\n", data);
      break;
    case 4:
      data = dequeueRear();
      printf("Deleted element is %d\n", data);
      break;
    case 5:
      printf("The first element of the queue is %d\n", peek());
      break;
    case 6:
      print();
      break;
    case 7:
      exit(1);
    default:
      printf("Invalid choice\n");
    }
  }
}

void enqueueFront(int data)
{
  if (isFull())
  {
    printf("Queue Overflow\n");
    exit(1);
  }
  if (front == -1)
  {
    front = 0;
    rear = 0;
  }
  else if (front == 0)
  {
    front = MAX - 1;
  }
  else
  {
    front = front - 1;
  }
  deque[front] = data;
}

void enqueueRear(int data)
{
  if (isFull())
  {
    printf("Queue Overflow\n");
    exit(1);
  }
  if (front == -1)
  {
    front = 0;
    rear = 0;
  }
  else if (rear == MAX - 1)
  {
    rear = 0;
  }
  else
  {
    rear = rear + 1;
  }
  deque[rear] = data;
}

int dequeueFront()
{
  int data;
  if (isEmpty())
  {
    printf("Queue Underflow\n");
    exit(1);
  }
  data = deque[front];
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

int dequeueRear()
{
  int data;
  if (isEmpty())
  {
    printf("Queue Underflow\n");
    exit(1);
  }
  data = deque[rear];
  if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else if (rear == 0)
  {
    rear = MAX - 1;
  }
  else
    rear = rear - 1;
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
  return deque[front];
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
      printf("%d ", deque[temp]);
      temp++;
    }
  }
  else
  {
    while (temp <= MAX - 1)
    {
      printf("%d ", deque[temp]);
      temp++;
    }
    temp = 0;
    while (temp <= rear)
    {
      printf("%d ", deque[temp]);
      temp++;
    }
  }
  printf("\n");
}