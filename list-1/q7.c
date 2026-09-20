#include <unistd.h>

#include <stdio.h>

#include <fcntl.h>
#include <string.h>
int main(){

char buffer[100];
int fd=open("example.txt",O_RDONLY | O_CREAT,0644);
if (fd==-1){
perror("open");
return 1;
}
off_t size=lseek(fd,0,SEEK_END);
lseek(fd,0,SEEK_SET);

if (size>=sizeof(buffer)){
size=sizeof(buffer)-1;
}
ssize_t bytes_read=read(fd,buffer,size);
if (bytes_read==-1){
perror("read");
return 1;
}
buffer[bytes_read]='\0';
int new_fd=open("example_2.txt",O_WRONLY | O_CREAT,0644);
ssize_t bytes_written=write(new_fd,buffer,strlen(buffer));
if (new_fd==-1){
perror("write");
close(fd);
return 1;
}
close(fd);
close(new_fd);
return 0;
}
