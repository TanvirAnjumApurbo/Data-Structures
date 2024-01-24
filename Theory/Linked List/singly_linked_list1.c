#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

struct node *createList();
void insertAtBeginning(struct node **head_ref);
void printList(struct node *head);

int main()
{
  struct node *head = NULL;

  head = createList();
  printList(head);

  insertAtBeginning(&head);
  printList(head);

  return 0;
}

struct node *createList()
{
  struct node *head = NULL, *newNode, *temp;
  int choice;

  do
  {
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->link = NULL;

    if (head == NULL)
    {
      head = newNode;
      temp = newNode;
    }
    else
    {
      temp->link = newNode;
      temp = newNode;
    }

    printf("Do you want to continue? (0 for No, 1 for Yes): ");
    scanf("%d", &choice);
  } while (choice);

  return head;
}

void insertAtBeginning(struct node **head_ref)
{
  struct node *newNode;

  newNode = (struct node *)malloc(sizeof(struct node));
  printf("Enter the data to insert at the beginning: ");
  scanf("%d", &newNode->data);

  newNode->link = *head_ref;
  *head_ref = newNode;
}

void printList(struct node *head)
{
  struct node *temp = head;
  printf("Linked List: ");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->link;
  }
  printf("\n");
}