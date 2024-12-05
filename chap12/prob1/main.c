#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define MAXLINE 100
int main(void){
	int n, len, fd[2], pid;
	char message[MAXLINE], line[MAXLINE];
	pipe(fd);
	if((pid=fork())==0){
		close(fd[0]);
		sprintf(message,"Hello from PID %d\n",getpid());
		len = strlen(message)+1;
		write(fd[1],message,len);
	}
	else{
		close(fd[1]);
		n=read(fd[0],line,MAXLINE);
		printf("[%d] %s",getpid(),line);
	}
	exit(0);
}
