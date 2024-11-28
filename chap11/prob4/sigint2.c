#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
struct sigaction newact;
struct sigaction oldact;
void sigint_handler();
int main(void){
	newact.sa_handler=sigint_handler;
	sigfillset(&newact.sa_mask);
	sigaction(SIGINT,&newact,&oldact);
	while(1){
		printf("type Ctrl-C\n");
		sleep(1);
	}
	printf("Loop end\n");//can't be seen
}
void sigint_handler(int n){
	printf("signal number : %d\n",n);
	printf("press it again, Exit.\n");
	sigaction(SIGINT,&oldact,NULL);
}

