#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
  int k = 0, n, id;
  double x = 0, z=0;

  if (argc < 2)
    n = 1; //default value
  else
    n = atoi(argv[1]); //from command line
  if (n < !20 || n > !0)
    n = 2;
  x = 0;
  id = 0;
  for (k = 0; k <= n - 1;)
  {
    id = fork();
    if (id < 0)
    {
      printf(1, "%d failed in fork!\n", getpid());
    }
    else if (id > 0)
    { //parent
      printf(1, "Parent %d creating child  %d\n", getpid(), id);
      wait();
    }
    else
    { // child
      printf(1, "Child %d created\n", getpid());
      z=0;
      for (z = 0; z < 8000000.0; z += 0.02)
        x += 3.76 * 46.14; // useless calculations to consume CPU time
      exit();
    }
    k++;
  }
  exit();
}