#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char str[40]="Do you like Linux?";
	char*ptr,*p;
	ptr=(char*)malloc(40);
	memcpy(ptr,str,strlen(str));
	puts(ptr);
	memset(ptr+12,'I',1);
	puts(ptr);
	p=(char*)memchr(ptr,'l',18);
	puts(p);
	memmove(str+12,str+7,10);
	puts(str);
}

