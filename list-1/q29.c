#include <stdio.h>
#include <sched.h>

int main()
{
    int policy;

    policy = sched_getscheduler(0);

    if(policy == -1)
    {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current Scheduling Policy: ");

    switch(policy)
    {
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;

        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;

        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
    }

    struct sched_param param;

    param.sched_priority = 50;

    if(sched_setscheduler(0,
                          SCHED_FIFO,
                          &param) == -1)
    {
        perror("sched_setscheduler");
        return 1;
    }

    printf("Scheduling policy changed to SCHED_FIFO\n");

    policy = sched_getscheduler(0);

    printf("New Policy: ");

    switch(policy)
    {
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;

        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;

        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
    }

    return 0;
}
