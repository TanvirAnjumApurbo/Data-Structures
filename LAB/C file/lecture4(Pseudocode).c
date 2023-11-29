array[n] 
top = -1

push(x)
{
  if(isFull())
    printf("Stack Overflow");
    else
    {
      top = top + 1;
      array[top] = x;
    }
}

pop()
{
  if(isEmpty())
    printf("Stack Underflow");
  else
  {
  top = top - 1;
}
}

isFull()
{
  if (top == n - 1)
    return true;
}

isEmpty()
{
  if (top == -1)
    return true;
}

top()
{
  return array[top];
}