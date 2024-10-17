#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[]){
	FILE *fp;
	if(argc < 2)
		printf("too few args\n");
		return(1);
	int i = 1;
	int num = 0;
	while(i < argc){
		int line = 0;
		if ((fp = fopen(argv[i], "r"))==NULL) {
			if (strcmp(argv[i], "-n")==0){
				num = 1;
				continue;
			}
			else{
				printf("file open error\n");
				return(2);
			}
		}
		char buffer[100];
		while(fgets(buffer, 100, fp) != NULL){
			line++;
			if (num)
				printf("%s", buffer);
			else 
				printf("%3d %s", line, buffer);
		}
		i++;
		printf("i=%d\n",i);
	}
	printf("argc=%d\n",argc);
}
