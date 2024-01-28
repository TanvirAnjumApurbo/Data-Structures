#include <stdio.h>
struct node
{
  int id;
  char name;
  struct node *next;
};

void main()
{
  // creating nodes
  struct node *A = malloc(sizeof(struct node));
  struct node *B = malloc(sizeof(struct node));
  struct node *C = malloc(sizeof(struct node));

  printf("A: %p\n", A);
  printf("B: %p\n", B);
  printf("C: %p\n", C);

  // assigning data to the nodes
  A->id = 10;
  B->id = 20;
  C->id = 30;

  A->name = 'A';
  B->name = 'B';
  C->name = 'C';

  // linking the nodes
  A->next = B;
  B->next = C;
  C->next = NULL; // If remove NULL, it will be a circular linked list

  // creating a head pointer
  struct node *head = A;

  // printing the data and next of the nodes
  struct node *temp = head;
  printf("head: %p\n", head);

  while (temp != NULL)
  {
    printf("id: %d name: %c\t", temp->id, temp->name);
    printf("next: %p\n", temp->next);
    temp = temp->next;
  }
}