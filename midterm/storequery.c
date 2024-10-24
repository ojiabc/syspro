#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include "item.h"
#define MAX_ID 999
int main(int argc, char*argv[]){
	int fd, id = 0;
	struct item record;
	if(argc != 2){
		fprintf(stderr, "How to use: %s file\n", argv[0]);
		exit(1);
	}
	if((fd = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(2);
	}
	printf("0: list of all goods, 1: list of available goods\n");
	int command;
	scanf("%d",&command);
	printf("%-3s %-20s %-20s %-12s %-8s\n", "ID", "Name", "Category", "Expired_date", "Stock"); 
	while(1){
		id++;
		lseek(fd, (id) * sizeof(record), SEEK_SET);
		if((read(fd, (char*)&record, sizeof(record)) > 0)&&record.date != 0){
			if(command == 1 && record.stock == 0)continue; 
			printf("%-3d %-20s %-20s %-12d %-8d\n", record.id, record.name, record.category, record.date, record.stock); 
		}
		else if(id > MAX_ID)  break;
	}
	close(fd);
	exit(0);
}

