#include<stdio.h>
#include<unistd.h>
int main(void){
	printf("current process id : [%d] \n",getpid());
	printf("parent process id : [%d] \n",getppid());
	return 0;
}
