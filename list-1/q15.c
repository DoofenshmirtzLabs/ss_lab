#include<stdio.h>
#include<unistd.h>

extern char **environ;
int main(){
	
	char **ptr=environ;

	while(*ptr!=NULL){
	
	printf("%s \n",*ptr);
	ptr++;
	
	}
	



return 0;
}
