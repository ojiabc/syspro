#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char*argv[]){
	long strtol();
	int new_mode;
	new_mode = (int)strtol(argv[1], (char**)NULL, 8);
	if(chmod(argv[2], new_mode) == -1){
		perror(argv[2]);
		exit(1);
	}
	exit(0);
}
