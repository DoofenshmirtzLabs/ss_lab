
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>


int main(){
	

	int fd=open("test_file.txt",O_RDWR);

	if(fd==-1){
	
	perror("open");
	return 1;
	}
	//flock is an posix data structure it seems for mainatianing information about lock
	struct flock lock;
	
	lock.l_type=F_WRLCK;
	lock.l_whence= SEEK_SET;//which part of file to lock ,seek_set means lock from beginningl
	lock.l_start=0;
	lock.l_len=0;//this mean lock the entire file down.


	printf("trying to acquire write locl...\n");

	if(fcntl(fd,F_SETLKW,&lock)==-1){
	perror("fcntl");
	close(fd);
	return 1;
	}

	printf("lock acquired succesfully \n");

	printf("file locked. press enter to relase \n");

	getchar();
	lock.l_type=F_UNLCK;
	if(fcntl(fd,F_SETLK,&lock)==-1){
	perror("fcntl unlocking");
	
	}
	printf("write lock relased \n");
	close(fd);
	



return 0;
}
