#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
//open the file and then go through the buffer and  store it in a line buffer till we find '\n' ,print and reset the line buffer
    char buffer[1000];
    char line_buffer[1000];
    int line_index = 0;

    ssize_t bytes; 

    int fd = open("q8.txt", O_RDONLY);

    if (fd < 0) {
        perror("OPEN");
        return 1;
    }



    
    while ((bytes = read(fd, buffer, sizeof(buffer))) > 0) {
        for (int i = 0; i < bytes; i++) {
            line_buffer[line_index++] = buffer[i];

            if (buffer[i] == '\n') {
                write(STDOUT_FILENO, line_buffer, line_index);
                line_index = 0;
            }
        }
    }

    // Handle last line if it doesn't end with '\n'
    if (line_index > 0) {
        write(STDOUT_FILENO, line_buffer, line_index);
    }

    
    if (bytes < 0) {
        char err_msg[] = "ERROR READING THE FILE \n";
        write(STDERR_FILENO, err_msg, sizeof(err_msg) - 1);
    }

    close(fd);
    return 0;
}
