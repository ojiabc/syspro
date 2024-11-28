#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
void intHandler();
int main(void){
	signal(SIGINT,intHandler);
	while(1){
		pause();
	}
	printf("Loop end\n");//can't be seen
}
void intHandler(int n){
	printf("Interrupt signal\n");
	printf("signal number : %d\n",n);
	exit(0);
}

