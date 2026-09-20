#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main()
{
    fd_set readfds;
    struct timeval tv;

    printf("Enter data within 10 seconds:\n");

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    int ret = select(
                STDIN_FILENO + 1,
                &readfds,
                NULL,
                NULL,
                &tv);

    if(ret == -1)
    {
        perror("select");
        return 1;
    }
    else if(ret == 0)
    {
        printf("Timeout! No input received within 10 seconds.\n");
    }
    else
    {
        if(FD_ISSET(STDIN_FILENO, &readfds))
        {
            char buffer[100];

            int n = read(STDIN_FILENO,
                         buffer,
                         sizeof(buffer));

            printf("Input received:\n");

            write(STDOUT_FILENO,
                  buffer,
                  n);
        }
    }

    return 0;
}

