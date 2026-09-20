	#include <stdio.h>
#include <unistd.h>

void use_execl()
{
    execl("/bin/ls", "ls", "-Rl", NULL);
}

void use_execlp()
{
    execlp("ls", "ls", "-Rl", NULL);
}

void use_execle()
{
    char *env[] = {
        "PATH=/bin:/usr/bin",
        NULL
    };

    execle("/bin/ls", "ls", "-Rl", NULL, env);
}

void use_execv()
{
    char *args[] = {
        "ls",
        "-Rl",
        NULL
    };

    execv("/bin/ls", args);
}

void use_execvp()
{
    char *args[] = {
        "ls",
        "-Rl",
        NULL
    };

    execvp("ls", args);
}

int main()
{
    printf("1. execl\n");
    printf("2. execlp\n");
    printf("3. execle\n");
    printf("4. execv\n");
    printf("5. execvp\n");

    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            use_execl();
            break;

        case 2:
            use_execlp();
            break;

        case 3:
            use_execle();
            break;

        case 4:
            use_execv();
            break;

        case 5:
            use_execvp();
            break;

        default:
            printf("Invalid Choice\n");
    }

    perror("exec failed");
    return 1;
}

