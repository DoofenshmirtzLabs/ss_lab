
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
//open file and then use fcntl to get file status flag and write switch case to find which access mode is the file in;
	int fd=open("test_file.txt",O_RDWR);
	if(fd==-1){
	perror("open");
	return 1;

	}

	//F_GETFL gives you flags using file descriptor;
	int flags=fcntl(fd,F_GETFL);

	if(flags==-1){
	perror("fcntl");
	return 1;
	
	}

	switch(flags & O_ACCMODE){
	
		case O_RDONLY:
			printf("file was opened in readonyl mode \n");
			break;

		case O_RDWR:
			printf("file was opened in read write mode \n");
			break;

		case O_WRONLY:

			printf("file was opened in write only mode");
			break;

		default:
			printf("UNKNOW MODE\n");
	
	
	}

	close(fd);
	







return 0;
}
