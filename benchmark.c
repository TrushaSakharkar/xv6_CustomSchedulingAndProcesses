#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf(1, "Usage: benchmark <n>\n");
        exit();
    }
    int i;
    int n;
    int j = 0;
    int k;
    int rtime;
    int wtime;
    int sums[3][2];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 2; j++)
            sums[i][j] = 0;
    n = atoi(argv[1]);
    i = n; //unimportant
    int pid;
    for (i = 0; i < 3 * n; i++)
    {
        j = i % 3;
        double x = 0;
        pid = fork();
        if (pid == 0)
        {                           //child
            j = (getpid() - 4) % 3; // ensures independence from the first son's pid when gathering the results in the second part of the program
            switch (j)
            {
            case 0: //CPU‐bound process (CPU):
                for (double z = 0; z < 800.0; z += 0.01)
                    x = x + 3.14 * 89.64; // useless calculations to consume CPU time
                break;
            case 1: //short tasks based CPU‐bound process (S‐CPU):
                // for (k = 0; k < 100; k++){
                // 	for (j = 0; j < 1000000; j++){}
                // }
                break;
            case 2: // simulate I/O bound process (IO)
                for (k = 0; k < 100; k++)
                {
                    sleep(1);
                }
                break;
            }
            exit(); // children exit here
        }
        continue; // father continues to spawn the next child
    }
    for (i = 0; i < 3 * n; i++)
    {
        pid = waitx(&wtime, &rtime);
        int res = (pid - 4) % 3; // correlates to j in the dispatching loop
        switch (res)
        {
        case 0: // CPU bound processes
            printf(1, "CPU-bound, pid: %d, running: %d, waiting: %d, turnaround: %d\n", pid, rtime, wtime, rtime + wtime);
            sums[0][0] += rtime;
            sums[0][1] += wtime;
            break;
        case 1: // CPU bound processes, short tasks
            // printf(1, "CPU-S bound, pid: %d, running: %d, waiting: %d, turnaround: %d\n", pid, rtime, wtime, rtime+wtime);
            // sums[1][0] += rtime;
            // sums[1][1] += wtime;
            break;
        case 2: // simulating I/O bound processes
            printf(1, "I/O bound, pid: %d, running: %d, waiting: %d, turnaround: %d\n", pid, rtime, wtime, rtime + wtime);
            sums[2][0] += rtime;
            sums[2][1] += wtime;
            break;
        }
    }
    for (i = 0; i < 3; i++)
        for (j = 0; j < 2; j++)
            sums[i][j] /= n;
    printf(1, "\n\nCPU bound:\nAverage running time: %d\nAverage sleeping time: %d\nAverage turnaround time: %d\n\n\n", sums[0][0], sums[0][1], sums[0][0] + sums[0][1]);
    // printf(1, "CPU-S bound:\nAverage running time: %d\nAverage sleeping time: %d\nAverage turnaround time: %d\n\n\n", sums[1][0], sums[1][1], sums[1][0] + sums[1][1]);
    printf(1, "I/O bound:\nAverage running time: %d\nAverage sleeping time: %d\nAverage turnaround time: %d\n\n\n", sums[2][0], sums[2][1], sums[2][0] + sums[2][1]);
    exit();
}