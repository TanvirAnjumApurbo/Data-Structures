#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *prev;
  int data;
  struct node *next;
};

struct node *addToEmpty(struct node *head, int data);
struct node *addAtBeg(struct node *head, int data);
struct node *addAtEnd(struct node *head, int data);
struct node *addAfterPos(struct node *head, int data, int pos);
struct node *addBeforePos(struct node *head, int data, int pos);
struct node *createEntireList(struct node *head);
void print(struct node *head);
struct node *delFirst(struct node *head);
struct node *delLast(struct node *head);
struct node *delInter(struct node *head, int pos);
struct node *reverse(struct node *head);

int main()
{
  struct node *head = NULL;
  struct node *ptr;

  head = addToEmpty(head, 22);

  head = addAtBeg(head, 11);

  head = addAtEnd(head, 33);

  head = addAfterPos(head, 44, 2);

  head = addBeforePos(head, 55, 3);

  head = delFirst(head);

  head = delLast(head);

  head = delInter(head, 2);

  head = reverse(head);

  // head = createEntireList(head);

  ptr = head;
  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }

  // print(head);

  return 0;
}

struct node *addToEmpty(struct node *head, int data)
{
  struct node *temp = malloc(sizeof(struct node));
  temp->prev = NULL;
  temp->data = data;
  temp->next = NULL;
  head = temp;
  return head;
}

struct node *addAtBeg(struct node *head, int data)
{
  struct node *temp = malloc(sizeof(struct node));
  temp->prev = NULL;
  temp->data = data;
  temp->next = head;

  if (head != NULL)
  {
    head->prev = temp;
  }

  head = temp;
  return head;
}

struct node *addAtEnd(struct node *head, int data)
{
  struct node *temp = malloc(sizeof(struct node));
  temp->prev = NULL;
  temp->data = data;
  temp->next = NULL;

  if (head == NULL)
  {
    head = temp;
    return head;
  }

  struct node *last = head;
  while (last->next != NULL)
  {
    last = last->next;
  }

  last->next = temp;
  temp->prev = last;

  return head;
}

struct node *addAfterPos(struct node *head, int data, int pos)
{
  struct node *newP = NULL;
  struct node *temp = head;
  struct node *temp2 = NULL;
  newP = addToEmpty(newP, data);
  while (pos > 1 && temp != NULL)
  {
    temp = temp->next;
    pos--;
  }

  if (temp == NULL)
  {
    printf("Invalid position.\n");
    free(newP);
    return head;
  }
  temp2 = temp->next;

  if (temp2 != NULL)
  {
    temp2->prev = newP;
  }

  temp->next = newP;
  newP->prev = temp;
  newP->next = temp2;

  return head;
}

struct node *addBeforePos(struct node *head, int data, int pos)
{
  struct node *newP = NULL;
  struct node *temp = head;
  struct node *temp2 = NULL;

  if (pos == 1)
  {
    head = addAtBeg(head, data);
    return head;
  }

  newP = addToEmpty(newP, data);

  while (pos > 2 && temp != NULL)
  {
    temp = temp->next;
    pos--;
  }

  if (temp == NULL)
  {
    printf("Invalid position.\n");
    free(newP);
    return head;
  }

  temp2 = temp->next;

  temp->next = newP;
  newP->prev = temp;
  newP->next = temp2;

  if (temp2 != NULL)
  {
    temp2->prev = newP;
  }

  return head;
}

struct node *createEntireList(struct node *head)
{
  int n, data, i;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  if (n == 0)
  {
    return head;
  }
  printf("Enter the data for node 1: ");
  scanf("%d", &data);
  head = addToEmpty(head, data);
  for (i = 1; i < n; i++)
  {
    printf("Enter the data for node %d: ", i + 1);
    scanf("%d", &data);
    head = addAtEnd(head, data);
  }
  return head;
}

void print(struct node *head)
{
  struct node *ptr = head;
  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

struct node *delFirst(struct node *head)
{
  head = head->next;
  free(head->prev);
  head->prev = NULL;
  return head;
}

struct node *delLast(struct node *head)
{
  struct node *temp = head;
  struct node *temp2;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp2 = temp->prev;
  temp2->next = NULL;
  free(temp);
  return head;
}

struct node *delInter(struct node *head, int pos)
{
  struct node *temp = head;
  struct node *temp2 = NULL;
  if (pos == 1)
  {
    head = delFirst(head);
    return head;
  }
  while (pos > 1)
  {
    temp = temp->next;
    pos--;
  }
  if (temp->next == NULL)
  {
    head = delLast(head);
  }
  else
  {
    temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2;
    free(temp);
    temp = NULL;
  }
  return head;
}

struct node *reverse(struct node *head)
{
  struct node *ptr1 = head;
  struct node *ptr2 = ptr1->next;
  ptr1->next = NULL;
  ptr1->prev = ptr2;

  while (ptr2 != NULL)
  {
    ptr2->prev = ptr2->next;
    ptr2->next = ptr1;
    ptr1 = ptr2;
    ptr2 = ptr2->prev;
  }
  head = ptr1;
  return head;
}