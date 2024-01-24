#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

void count_of_nodes(struct node *head);
void print_data(struct node *head);
void add_beg(struct node **head, int data);
struct node *add_at_end(struct node *ptr, int data);
void add_at_pos(struct node *head, int data, int pos);
struct node *del_first(struct node *head);
void del_last(struct node *head);
void del_pos(struct node **head, int pos);
struct node *reverse(struct node *head);
struct node *del_entire_list(struct node *head);

int main()
{
  struct node *head = malloc(sizeof(struct node));
  head->data = 45;
  head->link = NULL;

  struct node *ptr = malloc(sizeof(struct node));
  ptr->data = 98;
  ptr->link = NULL;
  head->link = ptr;

  int data = 3;
  add_beg(&head, data);

  ptr = add_at_end(ptr, 67);

  int data1 = 4, position = 3;
  add_at_pos(head, data1, position);

  head = del_first(head);

  del_last(head);

  int position1 = 2;
  del_pos(&head, position1);

  head = reverse(head);

  head = del_entire_list(head);

  count_of_nodes(head);
  print_data(head);

  return 0;
}

void count_of_nodes(struct node *head)
{
  int count = 0;
  if (head == NULL)
    printf("Linked List is empty\n");
  struct node *ptr = NULL;
  ptr = head;
  while (ptr != NULL)
  {
    count++;
    ptr = ptr->link;
  }
  printf("Number of nodes in the linked list is %d\n", count);
}

void print_data(struct node *head)
{
  if (head == NULL)
    printf("Linked List is empty\n");
  struct node *ptr = NULL;
  ptr = head;
  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->link;
  }
}

void add_beg(struct node **head, int data)
{
  struct node *ptr = malloc(sizeof(struct node));
  ptr->data = data;
  ptr->link = NULL;
  ptr->link = *head;
  *head = ptr;
}

struct node *add_at_end(struct node *ptr, int data)
{
  struct node *temp = malloc(sizeof(struct node));
  temp->data = data;
  temp->link = NULL;
  ptr->link = temp;
  return temp;
}

void add_at_pos(struct node *head, int data, int pos)
{
  struct node *ptr = head;
  struct node *ptr2 = malloc(sizeof(struct node));
  ptr2->data = data;
  ptr2->link = NULL;

  pos--;

  while (pos != 1)
  {
    ptr = ptr->link;
    pos--;
  }
  ptr2->link = ptr->link;
  ptr->link = ptr2;
}

struct node *del_first(struct node *head)
{
  if (head == NULL)
    printf("Linked List is empty\n");
  else
  {
    struct node *temp = head;
    head = head->link;
    free(temp);
    temp = NULL;
  }
  return head;
}

void del_last(struct node *head)
{
  if (head == NULL)
    printf("Linked List is empty\n");
  else if (head->link == NULL)
  {
    free(head);
    head = NULL;
  }
  else
  {
    struct node *temp = head;
    while (temp->link->link != NULL)
    {
      temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
  }
}

void del_pos(struct node **head, int pos)
{
  struct node *current = *head;
  struct node *previous = *head;
  if (*head == NULL)
  {
    printf("Linked List is already empty\n");
  }
  else if (pos == 1)
  {
    *head = current->link;
    free(current);
    current = NULL;
  }
  else
  {
    while (pos != 1)
    {
      previous = current;
      current = current->link;
      pos--;
    }
    previous->link = current->link;
    free(current);
    current = NULL;
  }
}

struct node *reverse(struct node *head)
{
  struct node *prev = NULL;
  struct node *next = NULL;
  while (head != NULL)
  {
    next = head->link;
    head->link = prev;
    prev = head;
    head = next;
  }
  head = prev;
  return head;
}

struct node *del_entire_list(struct node *head)
{
  struct node *temp = head;
  while (temp != NULL)
  {
    temp = temp->link;
    free(head);
    head = temp;
  }
  return head;
}