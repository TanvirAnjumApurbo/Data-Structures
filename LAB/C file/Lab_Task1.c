#include <stdio.h>

#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x);
void dequeue();
int isFull();
int isEmpty();
int Front();
void traversal();

void main()
{
  while (1)
  {
    int choice, x;
    printf("Enter choice (1.enqueue 2.dequeue 3.Front 4.exit): ");
    scanf("%d", &choice);
    if (choice == 1)
    {
      printf("Enter new data: ");
      scanf("%d", &x);
      enqueue(x);
      traversal();
    }
    else if (choice == 2)
    {
      dequeue();
      traversal();
    }
    else if (choice == 3)
    {
      printf("Front: %d\n", Front());
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

void enqueue(int x)
{
  if (isFull())
    printf("Queue Full\n");
  else
  {
    if (isEmpty())
    {
      front = 0;
    }
    rear++;
    queue[rear] = x;
  }
}

void dequeue()
{
  if (isEmpty())
    printf("Queue Empty\n");
  else
  {
    front++;
    if (front > rear)
    {
      front = -1;
      rear = -1;
    }
  }
}

int isFull()
{
  if (rear == SIZE - 1)
    return 1;
  else
    return 0;
}

int isEmpty()
{
  if (front == -1 && rear == -1)
    return 1;
  else
    return 0;
}

int Front()
{
  if (front != -1)
    return queue[front];
  else
    return 0;
}

void traversal()
{
  int i;
  if (isEmpty())
  {
    printf("Queue is Empty\n");
  }
  else
  {
    printf("Queue: ");
    for (i = front; i <= rear; i++)
    {
      printf("%d ", queue[i]);
    }
    printf("\n");
  }
}