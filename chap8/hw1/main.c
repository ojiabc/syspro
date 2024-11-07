#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pwd.h>
#include<grp.h>
#include<string.h>
int main(int argc, char*argv[]){
	if(argc<2)perror("Too few arguments\n");
	if(argc==2){
		if(strcmp(argv[1],"-e")==0){
			char**ptr;
			extern char**environ;
			for(ptr=environ;*ptr!=0;ptr++)printf("%s\n",*ptr);
		}
		else if(strcmp(argv[1],"-u")==0){
			printf("나의 실제 사용자 ID : %d(%s)\n",getuid(),getpwuid(getuid())->pw_name);
			printf("나의 유효 사용자 ID : %d(%s)\n",geteuid(),getpwuid(geteuid())->pw_name);
		}
		else if(strcmp(argv[1],"-g")==0){
			printf("나의 실제 그룹 ID : %d(%s)\n",getgid(),getgrgid(getgid())->gr_name);
			printf("나의 유효 그룹 ID : %d(%s)\n",getegid(),getgrgid(getegid())->gr_name);
		}
		else if(strcmp(argv[1],"-i")==0)
			printf("my process id : [%d]\n",getpid());
		else if(strcmp(argv[1],"-p")==0)
			printf("parent process id : [%d]\n",getppid());
	}
	if(argc==3){
		if(strcmp(argv[1],"-e")==0){
			char*ptr;
			ptr=getenv(argv[2]);
			printf("%s = %s\n",argv[2],ptr);
		}
	}
}
