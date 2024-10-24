#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLINE 80
int main(int argc, char*argv[]){
	FILE *fp;
	int line = 0;
	char buffer[MAXLINE];

	if(argc > 3){
		fprintf(stderr, "How to use: line FileName\nor\n line FileName Keyword\n");
		exit(1);
	}
	if((fp=fopen(argv[1],"r")) == NULL){
		fprintf(stderr, "Error Open File\n");
		exit(2);
	}
	if(argc == 3){
		while(fgets(buffer, MAXLINE, fp) != NULL){
			line++;
			printf("%s", buffer);
			if(line == 2) break;
		}
	}
	else if(argc == 4){
		while(fgets(buffer, MAXLINE, fp) != NULL){
			if(grep(buffer, argv[3])!=-1)
				printf("%s", buffer);
		}
	}
	exit(0);
}

