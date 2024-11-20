#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
#define MAXARG 10
int mysystem(int argc, char *argv[]){
    int child, pid, status;
    pid = fork();
    if(pid==0){
        execvp(argv[1],&argv[1]);
		exit(errno);
    }
    else if(pid > 0){
        child = wait(&status);
        printf("[%d]child process %d end\n",getpid(),pid);
        printf("\tend code %d\n",status>>8);
		return 1;
    }
	else{
		printf("fork error\n");
		return -1;
	}
}
int main(){
	printf("parental process start\n");
	char *cmds=NULL;
	size_t s=0;
	while(1){
		printf("[shell]");
		getline(&cmds,&s,stdin);
		if(strcmp(cmds,"exit\n")==0)break;

		const char *div=";";
		char *c;
		char *cmdl=strtok_r(cmds,div,&c);
		while(cmdl!=NULL){
			char *args[MAXARG];
			const char *div2=" ";
			char *c2;
			int n=0;
			args[n]=strtok_r(cmdl,div2,&c2);
			while(args[n]!=NULL&&n<MAXARG){
				n++;
				args[n]=strtok_r(NULL,div2,&c2);
			}
			args[n]=NULL;
			mysystem(n, args);
			cmdl=strtok_r(NULL,div,&c);
		}
	}
	free(cmds);
}
