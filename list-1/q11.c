
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main(){
	int fd=open("test_file.txt",O_RDWR);
	lseek(fd,0,SEEK_END);
	int fd1=dup(fd);
	int fd2=dup2(fd1,10);
	char *msg1="written using fd1";
	char *msg2="written using fd2";	
	write(fd1,msg1,strlen(msg1));
	write(fd2,msg2,strlen(msg2));
	close(fd);
	close(fd1);
	close(fd2);
	return 0;

}
