#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc, char*argv[]){
	int child, pid, status;
	pid = fork();
	if(pid==0){
		execvp(argv[1],&argv[1]);
		fprintf(stderr,"%s:실행 불가\n",argv[1]);
	}
	else{
		child = wait(&status);
		printf("[%d] 자식 프로세스 %d 종료\n",getpid(),pid);
		printf("\t종료 코드 %d\n",status>>8);
	}
}
