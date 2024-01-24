#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

void main()
{
  struct node *one = malloc(sizeof(struct node));
  struct node *two = malloc(sizeof(struct node));
  struct node *three = malloc(sizeof(struct node));

  one->data = 10;
  two->data = 20;
  three->data = 30;

  one->next = two;
  two->next = three;
  three->next = NULL;

  struct node *head = one;

  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = 40;
  newNode->next = NULL;

  // case-1: insert at the beginning
  // newNode->next = one;
  // head = newNode;

  // case-2: insert at the middle
  // newNode->next = three;
  // two->next = newNode;

  // case-3: insert at the end
  // three->next = newNode;

  // case-4: delete at beginning
  // head = two;
  // free(one);

  // case -5: delete at the middle
  // one->next = three;
  // free(two);

  // case-6: delete at the end
  // two->next = NULL;
  // free(three);

  struct node *temp = head;

  while (temp != NULL)
  {
    printf("data: %d next: %p\n", temp->data, temp->next);
    temp = temp->next;
  }
}