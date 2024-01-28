#include<stdio.h>

#define size 10

void enq(int x);
void deq();
int isFull();
int isEmpty();
int peek();
void print();

int queue[size];
int f=-1,r=-1;

int main()
{
    while(1)
    {
        int choice,x;
        printf("Enter choice: ");
        scanf("%d", &choice);
        if(choice==1){
            printf("Enter data: ");
        scanf("%d", &x);
        enq(x);
        print();
        }
        else if(choice==2)
        {
            deq();
            print();
        }
        else if(choice==3)
            printf("Peek: %d\n", peek());
        else if(choice==4)
            break;
        else
            printf("Invalid Choice\n");
    }
    return 0;
}


void enq(int x)
{
    if(isFull())
    {

        printf("Q is full\n");

    }
    else
    {
        if(f==-1)
            f=0;
        r++;
        queue[r]=x;
    }

}

void deq()
{
    if(isEmpty())
    {

        printf("Q Emty");

    }
    else
    {
                f++;
    if(f>r)
    {
        f=-1;
        r=-1;
    }
    }
}


int isFull()
{
    if(r==size-1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(f==-1||f==r+1)
        return 1;
    else
        return 0;
}

int peek()
{

    if(isEmpty())
    {

        printf("Khali");
        return -1;
    }
    else
        return queue[f];
}

void print()
{
     if (isEmpty())
  {
    printf("Queue is Empty\n");
  }
  else{
    printf("Q is: ");
    for(int i=f;i<=r;i++)
    {

        printf("%d ", queue[i]);

        }
        printf("\n");
  }
}
