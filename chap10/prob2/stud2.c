#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student{
	int id;
	char name[20];
	struct student *next;
}st;
int main(){
	int count=0,id;
	char name[20];
	st *p,*head=NULL;
	printf("학번과 이름을 입력하세요\n");
	while(scanf("%d %s",&id,name)==2){
		p=(st*)malloc(sizeof(st));
		if(p==NULL){
			perror("malloc");
			exit(1);
		}
		p->id=id;
		strcpy(p->name,name);
		p->next=head;
		head=p;
	}
	printf("\n* 학생 정보(역순) *\n");
	p=head;
	while(p!=NULL){
		count++;
		printf("학번: %d 이름: %s\n",p->id,p->name);
		st *t=p;
		p=p->next;
		free(t);
	}
	printf("총 %d 명입니다.\n",count);
	exit(0);

}
