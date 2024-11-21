#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
node push(node *top, int data);
int pop(node *top);

int main(void){
	int n = 0;
	node *head = (node*)malloc(sizeof(node));
	while(scanf("%d",&n)==1){
		push(head, n);		
	}
	printf("print stack\n");
	while(head->next!=NULL){
		printf("%d\n",pop(head));
	}
	printf("%d",pop(head));
}
node push(node *top, int data){
	node *nn = (node*)malloc(sizeof(node));
	nn->data = data;
	nn->next = NULL;
	node *n = top;
	while(n->next!=NULL){
		n = n->next;
	}
	n->next = nn;
}
int pop(struct node *top){
	node *n = top;
	node *p = NULL;
	while(n->next!=NULL){
		p = n;
		n = n->next;
	}
	int v;
	if(p!=NULL)p->next = NULL;
	v = n->data;
	free(n);
	return v;
}
