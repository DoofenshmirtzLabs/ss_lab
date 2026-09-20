#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
//have to create 5 new files inside an infinite loop 
	int counter=1;
	
	while(1){
		char filename[20];
		sprintf(filename,"file%d",counter);
		int fd=open(filename,O_CREAT | O_RDWR,0644);

		if (fd==-1){
		perror("open");
		return 1;
		}
		printf("file %d CREATED",counter);
		close(fd);
		counter+=1;
		
		if (counter==5){
			break;
		}

	
	
	}
	return 0;		
	




}
