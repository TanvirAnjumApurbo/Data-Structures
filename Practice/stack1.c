#include <stdio.h>
#define MAX 100

int isFull();
void push(char x);
void display();

char stack[MAX];
int top = -1;

void main()

{
    while (1)
    {
        int choice;
        char x;
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter new word: \n");
            scanf(" %c", &x);  // Add a space before %c to consume the newline character
            push(x);
            display();
        }
        else if (choice == 2)
        {
            break;
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }
    display();
    return;
}

void push(char x)
{
    if (isFull())
        printf("Stack Overflow: ");
    else
    {
        top = top + 1;
        stack[top] = x;
    }
}

int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

void display()
{
    int i;
    printf("Stack is: ");
    for (i = 0; i <= top; i++)
    {

        printf("%c", stack[i]);
    }
    printf("\n");
}
