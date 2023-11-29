#include <stdio.h>
#include <sys/time.h>

int main()
{
  struct timeval start, end;
  long seconds, microseconds;

  gettimeofday(&start, NULL); // Record the starting time

  // Your code to measure execution time here
  // For example:
  printf("Hello World!\n");

  gettimeofday(&end, NULL); // Record the ending time

  seconds = end.tv_sec - start.tv_sec;        // Calculate the seconds elapsed
  microseconds = end.tv_usec - start.tv_usec; // Calculate the microseconds elapsed

  double elapsed = seconds + microseconds / 1e6; // Total time elapsed in seconds

  printf("Elapsed time: %f seconds\n", elapsed);

  return 0;
}
