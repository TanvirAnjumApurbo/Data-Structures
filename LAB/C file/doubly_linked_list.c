#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *prev;
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

  one->prev = NULL;
  one->next = two;
  two->prev = one;
  two->next = three;
  three->prev = two;
  three->next = NULL;

  struct node *head = one;

  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = 40;
  newNode->next = NULL;
  newNode->prev = NULL;

  // case -1: insert at the beginning
  // newNode->next = one;
  // one->prev = newNode;
  // head = newNode;

  // case-2: insert at the middle
  // newNode->prev = one;
  // newNode->next = two;
  // one->next = newNode;
  // two->prev = newNode;

  // case-3: insert at the end
  // newNode->prev = three;
  // three->next = newNode;

  // case-4: delete at the beginning
  // head = two;
  // two->prev = NULL;
  // free(one);

  // case-5: delete at the middle
  // one->next = three;
  // three->prev = one;
  // free(two);

  // case-6: delete at the end
  // two->next = NULL;
  // free(three);

  struct node *temp = head;

  while (temp != NULL)
  {
    printf("prev: %p data: %d next: %p\n", temp->prev, temp->data, temp->next);
    temp = temp->next;
  }
}