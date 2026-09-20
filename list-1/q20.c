#include<unistd.h>
#include<stdio.h>

int main(){

	pid_t pid=fork();
	if (pid==0){
	printf("child id: %d \n",getpid());
	printf("parent id:%d \n",getppid());
	}
	else if(pid>0){
	printf("parent id:%d \n",getpid());
	printf("child id: %d",pid);
	}
	else {
	
	printf("error \n");
	}



return 0;
}
