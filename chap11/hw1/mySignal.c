#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
struct sigaction newact;
struct sigaction oldact;
void myIntHandler();
void mySignal(int signal_number,void(*func)(int)){
	newact.sa_handler=myIntHandler;
	sigfillset(&newact.sa_mask);
	sigaction(signal_number,&newact,&oldact);
}
int main(int argc,char*argv[]){
	mySignal(SIGINT,myIntHandler);
	int i = 0;
	while(1){
		sleep(1);
		i++;
		printf("%d second\n",i);
	}
	printf("Loop end\n");//can't be seen
}
void myIntHandler(int n){
	printf("Interrupt detected\n");
	exit(0);
}

