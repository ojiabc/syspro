#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char*argv[]){
	if(argc<2)alarm(5);
	else alarm(atoi(argv[1]));
	printf("Loop start\n");
	short i=0;
	while(1){
		sleep(1);
		i++;
		printf("%d second\n",i);
	}
	printf("Loop end\n");
	return 0;
}
