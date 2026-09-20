#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/wait.h>
int main(){
	int fd=open("test_file.txt",O_RDWR);

	pid_t pid=fork();
	if(pid<0){
	perror("fork");
	return 1;
	}

	if (pid==0){
	printf("child process writing into file:%d \n",getpid());
	char msg[]="this is written by child process \n";
	lseek(fd,0,SEEK_END);
	write(fd,msg,strlen(msg));
	return 0;
	}
	else{
	printf("parent process writing into file:%d \n",getpid());
	char msg[]="this is written by parent process \n";
	lseek(fd,0,SEEK_END);
	write(fd,msg,strlen(msg));
	wait(NULL);
	
	}
return 0;
}
