#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *insert_node(struct node *root, int data)
{
  if (root == NULL)
  {
    root = (struct node *)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
  }
  else if (data < root->data)
  {
    struct node *insert_node(struct node * root, int data)
    {
      if (root == NULL)
      {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
      }
      else if (data < root->data)
      {
        root->left = insert_node(root->left, data);
      }
      else if (data > root->data)
      {
        root->right = insert_node(root->right, data);
      }
      return root;
    }
  }
  else if (data > root->data)
  {
    root->right = insert_node(root->right, data);
  }
  return *root;
}

void levelOrder(struct node *root)
{
  if (root == NULL)
  {
    return;
  }

  struct node *queue[100];
  int front = -1, rear = -1;

  queue[++rear] = root;

  while (front != rear)
  {
    struct node *temp = queue[++front];
    printf("%d ", temp->data);

    if (temp->left != NULL)
    {
      queue[++rear] = temp->left;
    }

    if (temp->right != NULL)
    {
      queue[++rear] = temp->right;
    }
  }
}

bool search_key(struct node *root, int key)
{
  while (root != NULL)
  {
    if (key == root->data)
    {
      return true;
    }
    else if (key < root->data)
    {
      root = root->left;
    }
    else if (key > root->data)
    {
      root = root->right;
    }
  }
  return false;
}

int main()
{
  struct node *root = NULL;
  int choice, data;

  do
  {
    printf("Enter the data: ");
    scanf("%d", &data);
    root = insert_node(root, data);

    printf("Do you want to continue? (0 for No, 1 for Yes): ");
    scanf("%d", &choice);
  } while (choice);

  levelOrder(root);

  return 0;
}
