#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
int main(){
int fd=creat("test_q3.txt",0644);
if (fd==-1){
if (errno==EEXIST){
printf("some other process is running\n");
return 1;
}
else{
perror("creat");
return 1;
}
}
printf("fd:%d \n",fd);
while (1) {
    creat("file1.txt", 0644);
    creat("file2.txt", 0644);
    creat("file3.txt", 0644);
    creat("file4.txt", 0644);
    creat("file5.txt", 0644);
}
return 1;

}
