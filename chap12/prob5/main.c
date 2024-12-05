#include<stdio.h>
#include<unistd.h>
#define M 100
int main(int argc,char*argv[]){
	char line[M];
	FILE *fpin;
	if((fpin=popen(argv[1],"r"))==NULL){
		perror("popen error");
		return 1;
	}
	printf("result from children process\n");
	while(fgets(line,M,fpin))fputs(line,stdout);
	pclose(fpin);
	return 0;
}
