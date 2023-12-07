// Linear Search
// Binary Search

linearSearch(int data)
{
  for (i = 0; i < n; i++)
  {
    if (A[i] == data)
    {
      return i;
    }
  }
  return -1;
}

BinarySearch(data, low, high)
{
  while (low > high)
  {
    mid = (low + high) / 2;
    if (data == A[mid])
    {
      return mid;
    }
    else if (data < A[mid])
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return -1;
}

// Recursive Method

BinarySearch(data, low, high)
{
  if (low > high)
  {
    return -1;
  }
  mid = (low + high) / 2;
  if (data == a[mid])
  {
    return mid;
  }
  else
  {
    if (data < a[mid])
    {
      return BinarySearch(data, low, mid - 1);
    }
    else
    {
      return BinarySearch(data, mid + 1, high);
    }
  }