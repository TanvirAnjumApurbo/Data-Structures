isFull()
{
  if (rear == n - 1)
    return 1;
  else
    return 0;
}

isEmpty()
{
  if (front == -1 && rear == -1)
    return 1;
  else
    return 0;
}

void enqueue(int x)
{
  if (isFull())
    printf("Queue is full\n");
  else
  {
    if (isEmpty())
    {
      front++;
      rear++;
      A[rear] = x;
    }
  }
}

dequeue()
{
  if (isEmpty())
    printf("Queue is empty\n");
  else
  {
    front++;
    if (front > rear)
    {
      front = -1;
      rear = -1;
    }
  }
}