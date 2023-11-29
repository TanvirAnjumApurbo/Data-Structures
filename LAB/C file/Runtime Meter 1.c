#include <stdio.h>
#include <time.h>

int main()
{
  clock_t start_time, end_time;
  double cpu_time_used;

  start_time = clock(); // Record the starting time

  // Your code to measure execution time here
  // For example:
  printf("Hello World!\n");

  end_time = clock(); // Record the ending time

  cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // Calculate the CPU time used

  printf("CPU time used: %f seconds\n", cpu_time_used);

  return 0;
}
