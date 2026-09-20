#include<sched.h>
#include<stdio.h>
#include<unistd.h>


int main(){

	int min=sched_get_priority_min(SCHED_FIFO);
	int max=sched_get_priority_max(SCHED_FIFO);
	printf("max - min :%d \n",max-min);

	sleep(20);

return 0;
}
