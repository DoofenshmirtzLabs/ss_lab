#include <stdio.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <sys/stat.h>
int main(){
if (symlink("original.txt","soft.txt")==-1){
	perror("symlink");
	}
else{
	printf("softlink created ");
}
if(link("original.txt","hard.txt")==-1){
	perror("link");
}
else{
printf("hardlink created");
}
if(mkfifo("myfifo",0666)==-1){
perror("mkfifo");}

else{
printf("Fifo created succesfully.\n");
}
return 0;
}		
