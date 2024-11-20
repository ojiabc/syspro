#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int mysystem(const char*cmdstr){
	int pid,status;
	if(cmdstr==NULL)return 1;
	pid=fork();
	if(pid==-1)return -1;
	if(pid==0){
		execl("/bin/sh","sh","-c",cmdstr,(char*)0);
		_exit(127);
	}
	do{
		if(waitpid(pid,&status,0)==-1){
			if(errno!=EINTR)return -1;
		}
		else return status;
	}while(1);
}
int main(){
	int status;
	if((status = mysystem("date"))<0)perror("system() error");
	printf("end code %d\n", WEXITSTATUS(status));
	if((status = mysystem("hello"))<0)perror("system() error");
	printf("end code %d\n", WEXITSTATUS(status));
	if((status = mysystem("who; exit 44"))<0)perror("system() error");
	printf("end code %d\n",WEXITSTATUS(status));
}
