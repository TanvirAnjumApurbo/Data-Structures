#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data1;
    float data2;
    struct node *next
};

int main()
{
    struct node *one = malloc(sizeof(struct node));
    struct node *two = malloc(sizeof(struct node));
    struct node *three = malloc(sizeof(struct node));

    one->data1 = 11;
    one->data2 = 2.59;
    two->data1 = 12;
    two->data2 = 2.79;
    three->data1 = 13;
    three->data2 = 3.54;

    one->next = two;
    two->next = three;
    three->next = one;

    struct node *head = one;
    struct node *temp = head;

    do
    {
        printf("%d, %f, %p\n", temp->data1, temp->data2, temp->next);
        temp = temp->next;
    } while (temp != head);

    return 0;
}
