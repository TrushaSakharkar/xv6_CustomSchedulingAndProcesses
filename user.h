struct stat;
struct rtcdate;
struct proc_stat
{
  int inuse[64];           // Checks if its in use or not 
  int pid[64];             // PID of each process
  uint runtime[64];       //  Use suitable unit of time
  int num_run[64];         // Number of time the process is executed
  int current_queue[64];   // Current assigned queue
  int ticks[64][5];        // Number of ticks each process has received at each of the 5 priority queue
};

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int chprty( int pid, int priority );
int close(int);
int kill(int);
int exec(char*, char**);
int getpinfo(struct proc_stat* pstat);
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int cps(void);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
int waitx(int* wtime,int* rtime);

// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, const char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);