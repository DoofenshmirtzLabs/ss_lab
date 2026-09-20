#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
int main(int argc,char *argv[]){
	//take file name as input from terminal and display all the stat details
	if(argc!=2){
	printf("wrong input format,expected input format:<./q9><filename>");
	return 1;
	}

	struct stat st;

	
	if((stat(argv[1],&st))==-1){
	perror("stat");
	return 1;
	}
	//should i just use printf? or write? idk i mean write can handle differrent datatypes without any flags? ill just stick with printf for now
	printf("file name:%s",argv[1]);
	printf("inode number:%lu \n",st.st_ino);
	printf("number of hardlinks:%lu \n",st.st_nlink);
	printf("uid:%u \n",st.st_uid);
	printf("gid:%u \n",st.st_gid);
	printf("size of file:%ld \n",st.st_size);
 	printf("block size:%ld bytes\n",st.st_blksize);
 	printf("time of last access:%s \n",ctime(&st.st_atime));
	printf("time of last modification:%s \n",ctime(&st.st_mtime));
	printf("time of last change:%s \n",ctime(&st.st_ctime));
	return 0;
}
