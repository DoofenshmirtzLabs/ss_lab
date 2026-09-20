//open a i	file in readwrite mode and write 10 bytes and move the file pointer by 10bytes using lseek and write another 10 bytes

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[]){


	if (argc!=2){
	printf("incorrect input formt,expected format:<./q_10><filename>");
	return 1;
	}
	//open the file if exists if not create the file 
	int fd=open(argv[1],O_RDWR | O_CREAT,0644);
	
	if(fd==-1){
	perror("open");
	return 1;
	}

	char buffer[1024]="THIS AN MSG TO INFORM YOU THAT YOUR ARE NUTSS!!";	
	write(fd,buffer,10);
	//10 bytes from start ? or current position?its current may be 
	lseek(fd,10,SEEK_CUR);

	write(fd,buffer,10);
	close(fd);



return 0;
}
