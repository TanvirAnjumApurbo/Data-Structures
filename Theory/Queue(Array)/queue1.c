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