#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char **argv){
	DIR *dp;
	char *dir;
	struct dirent *d;
	struct stat st;
	char path[BUFSIZ + 1];
	if(argc == 1)
		dir = ".";
	else dir = argv[1];
	if((dp = opendir(dir)) == NULL)
		perror(dir);
	while((d = readdir(dp)) != NULL){
		int i = 1;
		printf("%s", d->d_name);
		while(i < argc){
			if(strcmp("-i", argv[i]) == 0)
				printf(" %lu", d->d_ino);
			if(strcmp("-t", argv[i]) == 0)
				printf(" %d", d->d_type);
			if(strcmp("-o", argv[i]) == 0)
				printf(" %ld", d->d_off);
			i++;
		}
		printf("\n");
	}
	closedir(dp);
	exit(0);
}
