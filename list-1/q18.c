#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

    int fd = open("records.txt", O_RDWR);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;

    // Lock Record 3
    // Assume each record = 20 bytes
    lock.l_start = 40;
    lock.l_len = 20;

    printf("Trying to acquire write lock...\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        return 1;
    }

    printf("Write lock acquired!\n");

    printf("Doing some work...\n");

    sleep(10);

    printf("Releasing lock...\n");

    lock.l_type = F_UNLCK;

    fcntl(fd, F_SETLK, &lock);

    close(fd);

    return 0;
}
