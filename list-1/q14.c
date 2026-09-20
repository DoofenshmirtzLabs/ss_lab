
#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){

	if(argc!=2){
	printf("wrong input format");
	return 1;
	}
	struct stat st;
	if((stat(argv[1],&st))==-1){
	perror("stat");
	return 1;
	}
	if(S_ISREG(st.st_mode)){
	printf("regular file");
	
	}

	else if(S_ISDIR(st.st_mode)){
	printf("its an directory");
	}
	else if(S_ISCHR(st.st_mode)){
        printf("its an char device");
        }
	else if(S_ISLNK(st.st_mode)){
        printf("its an SYMBOLIC LINK");
        }
	else if(S_ISBLK(st.st_mode)){
        printf("its an BLOCK DEVICE");
        }
	else if(S_ISFIFO(st.st_mode)){
        printf("its an NAMED PIPE");
        }
	else if(S_ISSOCK(st.st_mode) ){
        printf("its an SOCKET FILE");
        }
	else{
	printf("unknow file type");
	}





return 0;}
