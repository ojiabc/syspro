#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#define M 100
#define READ 0
#define WRITE 1
int main(int argc,char*argv[]){
	char str[1024];
	char*cmd1,*cmd2;
	int fd[2];
	printf("[shell]");
	fgets(str,sizeof(str),stdin);
	str[strlen(str)-1]='\0';
	if(strchr(str,'|')!=NULL){
		cmd1=strtok(str,"| ");
		cmd2=strtok(NULL,"| ");
	}
	pipe(fd);
	if(fork()==0){
		close(fd[READ]);
		dup2(fd[WRITE],1);
		close(fd[WRITE]);
		execlp(cmd1,cmd1,NULL);
		perror("pipe");
	}
	else{
		close(fd[WRITE]);
		dup2(fd[READ],0);
		close(fd[READ]);
		execlp(cmd2,cmd2,NULL);
		perror("pipe");
	}
	exit(0);
}
