#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define M 100
int main(){
	int fd,len,i;
	char message[M];
	sprintf(message,"Hello from PID %d",getpid());
	len=strlen(message)+1;
	do{
		fd=open("myPipe",O_WRONLY);
		if(fd==-1)sleep(1);
	}while(fd==-1);
	for(i=0;i<=3;i++){
		write(fd,message,len);
		sleep(3);
	}
	close(fd);
	return 0;
}
