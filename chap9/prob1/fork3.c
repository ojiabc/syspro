#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	int pid1,pid2,pid3,pid2_1;
	pid1=fork();
	printf("fork1 ...\n");
	if(pid1==0){
		printf("[Child 1] : Hello, world ! pid=%d\n",getpid());
		exit(0);
	}
	pid2=fork();
	printf("fork2 ...\n");
	if(pid2==0){
		printf("[Child 2] : Hello, world ! pid=%d\n",getpid());
/*
		for(int i=0;i<5;i++)printf("%d\n",i+5);
		pid2_1=fork();
		if(pid2_1==0){
			printf("2-1\n");
			exit(0);
		}
		else{printf("2\n");}
*/
		exit(0);
	}
	pid3=fork();
	printf("fork3 ...\n");
	if(pid3==0){
		printf("[Child 3] : Hello, world ! pid=%d\n",getpid());
		exit(0);
	}
	for(int i=0;i<5;i++)printf("%d\n",i);
	printf("[PARENT] : Hello,world ! pid=%d\n",getpid());
}
