#include <unistd.h>
#include <stdio.h>

#include <fcntl.h>

int main(){

int fd=open("test_3.txt",O_RDONLY | O_CREAT | O_EXCL,0644);
printf("fd:%d",fd);
return 1;
}
