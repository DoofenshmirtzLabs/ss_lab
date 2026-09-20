#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
#include<error.h>


int main(){
	errno=0;
	int priority=getpriority(PRIO_PROCESS,0);

	if (errno !=0){
	
		perror("get priority failed");
		return 1;
	}
	printf("inital nice value: %d \n",priority);
	printf("increasing nice vlaue by 5... \n");

	int new_nice =nice(5);

	if(new_nice==-1 && errno !=0){
		perror("nice failed");
		return 1;
	
	}
	priority=getpriority(PRIO_PROCESS,0);
	printf("new nice values: %d \n",priority);

	printf("setting nice value to 10 via setpriority() ... \n");

	if(setpriority(PRIO_PROCESS,0,10)==-1){
		perror("set priority failed");
		return 1;
	}

	priority=getpriority(PRIO_PROCESS,0);
	printf("final nice value:%d \n",priority);
	

return 0;
}
