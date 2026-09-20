#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    pid_t pid;

    pid = fork();

    if(pid < 0)
    {
        exit(1);
    }

    if(pid > 0)
    {
        exit(0);
    }

    setsid();

    while(1)
    {
        time_t now;
        struct tm *current;

        time(&now);

        current = localtime(&now);

        /*
           Run the script at 18:30
        */

        if(current->tm_hour == 18 &&
           current->tm_min == 30)
        {
            system("./myscript.sh");

            sleep(60);
        }

        sleep(10);
    }

    return 0;
}
