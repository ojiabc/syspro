#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
node* addq(node *head, node *tail, int data);
int delete(node *head, node **tail);

int main(void){
	node *head = (node*)malloc(sizeof(node));
	node *tail = head;
	int n;
	while(scanf("%d",&n)==1){
		tail = addq(head, tail, n);
	}
	printf("print queue\n");
	while(head!=tail){
		printf("%d\n",delete(head, &tail));
	}	
}

node* addq(node *head, node *tail, int data){
	node* nn = (node*)malloc(sizeof(node));
	nn->data = data;
	tail->next = nn;
	return nn;
}

int delete(node *head, node **tail){
	node *n = head;
	int v;
	while(n->next!=NULL&&n->next!=*tail){
		n = n->next;
	}
	n->next=NULL;
	v = (*tail)->data;
	free(*tail);
	*tail = n;
	return(v);
}
