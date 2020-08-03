#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

//Changes priority of a particular pid
int
main(int argc, char *argv[])
{
  int priority, pid;

  if(argc < 3){
      printf(2, "Usage: xpri pid priority\n" );
      sleep(1);
      exit();
  }
  priority = atoi ( argv[2] );
  pid = atoi ( argv[1] );
  if ( priority < 0 || priority > 100 ) {
      printf(2, "Invalid priority (0-100)!\n" );
      exit();
  }
  chprty ( pid, priority );

  exit();
}