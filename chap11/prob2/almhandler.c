#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
void alarmHandler(int n);
int main(int argc,char*argv[]){
	signal(SIGALRM,alarmHandler);
	if(argc<2)alarm(5);
	else alarm(atoi(argv[1]));
	short i=0;
	while(1){
		sleep(1);
		i++;
		printf("%d second\n",i);
	}
	printf("Loop end\n");//can't be seen
}
void alarmHandler(int n){
	printf("Wake up\n");
	exit(0);
}

