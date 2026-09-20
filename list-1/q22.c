
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(){

	pid_t pid= fork();
	
	if(pid==0){
	printf("child pid:%d",getpid());
	printf("child is exiting .. \n");
	exit(0);
	}
	else{
	
	printf("parent sleeping...");
	sleep(30);

	}



return 0;
}
