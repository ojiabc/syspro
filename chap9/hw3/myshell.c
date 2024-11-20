#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
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
	char *cmds=NULL;
	size_t s=0;
	while(1){
		printf("[shell]");
		getline(&cmds,&s,stdin);

		if(strcmp(cmds,"exit\n")==0)break;

		const char *div=";";
		char *c;
		char *cmd=strtok_r(cmds,div,&c);
		int m=0;
		while(cmd!=NULL){
			mysystem(cmd);
			cmd=strtok_r(NULL,div,&c);
			m++;
		}
	}
	free(cmds);
}
