#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  struct proc_stat* px = malloc (sizeof (struct proc_stat)) ;

  getpinfo(px);
  printf(1,"PID\tINUSE\tRUNTIME\tNUM_RUN\tCURR_Q\n");
  for (int i = 0; i < 64; i++)
  {
    if(px->runtime[i]>0)
    printf(1,"%d\t%d\t%d\t%d\t%d\n",px->pid[i],px->inuse[i],px->runtime[i],px->num_run[i],px->current_queue[i]);
  }
  
  exit();
}