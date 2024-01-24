#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *circularSingly(int data);
struct node *addAtBeg(struct node *tail, int data);
void print(struct node *tail);
struct node *addAtEnd(struct node *tail, int data);
struct node *addAfterPos(struct node *tail, int data, int pos);
struct node *createList(struct node *tail);
struct node *delFirst(struct node *tail);
struct node *delLast(struct node *tail);
struct node *delInter(struct node *tail, int pos);
void countElements(struct node *tail);

int main()
{
  // int data = 34;
  struct node *tail;
  // tail = circularSingly(data);
  // printf("%d", tail->data);

  tail = addAtBeg(tail, 22);
  tail = addAtBeg(tail, 11);
  tail = addAtEnd(tail, 33);
  tail = addAfterPos(tail, 44, 2);
  tail = addAfterPos(tail, 55, 3);
  tail = delFirst(tail);
  tail = delLast(tail);
  tail = delInter(tail, 2);
  print(tail);
  countElements(tail);

  return 0;
}

struct node *circularSingly(int data)
{
  struct node *temp = malloc(sizeof(struct node));
  temp->data = data;
  temp->next = temp;
  return temp;
}

struct node *addAtBeg(struct node *tail, int data)
{
  struct node *newP = malloc(sizeof(struct node));
  newP->data = data;
  newP->next = tail->next;
  tail->next = newP;
  return tail;
}

void print(struct node *tail)
{
  struct node *ptr = tail->next;
  do
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  } while (ptr != tail->next);
  if (tail == NULL)
  {
    printf("List is empty");
  }
  else
  {
    do
    {
      printf("%d ", ptr->data);
      ptr = ptr->next;
    } while (ptr != tail->next);
  }
  printf("\n");
}

struct node *addAtEnd(struct node *tail, int data)
{
  struct node *newP = malloc(sizeof(struct node));
  newP->data = data;
  newP->next = NULL;
  newP->next = tail->next;
  tail->next = newP;
  tail = tail->next;
  return tail;
}

struct node *addAfterPos(struct node *tail, int data, int pos)
{
  struct node *p = tail->next;
  struct node *newP = malloc(sizeof(struct node));
  newP->data = data;
  newP->next = NULL;
  while (pos > 1)
  {
    p = p->next;
    pos--;
  }
  newP->next = p->next;
  p->next = newP;
  if (p == tail)
  {
    tail = tail->next;
  }
  return tail;
}

struct node *createList(struct node *tail)
{
  int data, i, n;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  if (n == 0)
  {
    return tail;
  }
  printf("Enter the data for node 1: ");
  scanf("%d", &data);
  tail = addAtBeg(tail, data);
  for (i = 1; i < n; i++)
  {
    printf("Enter the data for node %d: ", i + 1);
    scanf("%d", &data);
    tail = addAtEnd(tail, data);
  }
  return tail;
}

struct node *delFirst(struct node *tail)
{
  if (tail == NULL)
    return tail;
  if (tail->next == tail)
  {
    free(tail);
    tail = NULL;
    return tail;
  }
  struct node *temp = tail->next;
  tail->next = temp->next;
  free(temp);
  temp = NULL;
  return tail;
}

struct node *delLast(struct node *tail)
{
  if (tail == NULL)
    return tail;
  struct node *temp = tail->next;
  if (tail->next == tail)
  {
    free(tail);
    tail = NULL;
    return tail;
  }
  while (temp->next != tail)
  {
    temp = temp->next;
  }
  temp->next = tail->next;
  free(tail);
  tail = temp;
  return tail;
}

struct node *delInter(struct node *tail, int pos)
{
  if (tail == NULL)
    return tail;
  struct node *temp = tail->next;
  if (tail->next == tail)
  {
    free(tail);
    tail = NULL;
    return tail;
  }
  while (pos > 2)
  {
    temp = temp->next;
    pos--;
  }
  struct node *temp2 = temp->next;
  temp->next = temp2->next;
  if (temp2 == tail)
  {
    tail = temp;
  }
  free(temp2);
  temp2 = NULL;
  return tail;
}

void countElements(struct node *tail)
{
  struct node *temp = tail->next;
  int count = 0;
  while (temp != tail)
  {
    temp = temp->next;
    count++;
  }
  count++;
  printf("Number of elements in the list: %d\n", count);
}