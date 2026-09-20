#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int fd = open("ticket.txt", O_RDWR);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Create write lock
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Trying to acquire WRITE lock...\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("WRITE lock acquired.\n");

    // Go to beginning of file
    lseek(fd, 0, SEEK_SET);

    char buffer[100];

    ssize_t n = read(fd, buffer, sizeof(buffer) - 1);

    if (n == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[n] = '\0';

    // Convert string to integer
    int ticket = atoi(buffer);

    // Increment ticket
    ticket++;

    printf("New ticket number: %d\n", ticket);

    // Convert integer back to string
    sprintf(buffer, "%d", ticket);

    // Remove old contents
    ftruncate(fd, 0);

    // Go back to beginning
    lseek(fd, 0, SEEK_SET);

    // Write updated ticket number
    if (write(fd, buffer, strlen(buffer)) == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    // Release lock
    lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("unlock");
        close(fd);
        return 1;
    }

    printf("WRITE lock released.\n");

    close(fd);

    return 0;
}

