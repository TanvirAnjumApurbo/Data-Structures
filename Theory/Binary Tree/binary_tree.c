#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *create();
void preOrder(struct node *);
void inOrder(struct node *);
void postOrder(struct node *);
void levelOrder(struct node *);

int main()
{
  struct node *root;
  root = NULL;
  root = create();

  printf("Preorder traversal: ");
  preOrder(root);

  printf("\nInorder traversal: ");
  inOrder(root);

  printf("\nPostorder traversal: ");
  postOrder(root);

  printf("\nLevelorder traversal: ");
  levelOrder(root);

  return 0;
}

struct node *create()
{
  int x;
  struct node *newNode;

  printf("Enter the data (or -1 to terminate): ");
  scanf("%d", &x);

  if (x == -1)
  {
    return NULL;
  }

  newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = x;

  printf("Enter the left child of %d:\n", x);
  newNode->left = create();

  printf("Enter the right child of %d:\n", x);
  newNode->right = create();

  return newNode;
}

void preOrder(struct node *root)
{
  if (root == NULL)
  {
    return;
  }

  printf("%d ", root->data);
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(struct node *root)
{
  if (root == NULL)
  {
    return;
  }

  inOrder(root->left);
  printf("%d ", root->data);
  inOrder(root->right);
}

void postOrder(struct node *root)
{
  if (root == NULL)
  {
    return;
  }

  postOrder(root->left);
  postOrder(root->right);
  printf("%d ", root->data);
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