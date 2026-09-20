#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>


int main(){
	int status;
	pid_t pid=fork();

	if (pid==0){
	
	sleep(5);
	printf("child pid=%d \n",getpid());
	}
	else{
	pid_t pid2=fork();
	if (pid2==0){
	sleep(10);
	printf("child2 pid=%d \n",getpid());

	}
	
	waitpid(pid2,&status,0);
	printf("parent finished waiting for child 2");
	}


return 0;
}
