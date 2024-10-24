#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include "item.h"
int main(int argc, char *argv[]){
	int fd;
	struct item record;
	if(argc < 2){
		fprintf(stderr, "How to use: %s file\n", argv[0]);
		exit(1);
	}
	if((fd = open(argv[1], O_RDWR|O_CREAT|O_EXCL, 0640)) == -1){
		perror(argv[1]);
		exit(2);
	}
	printf("%-2s %-10s %-10s %-4s %-4s\n", "ID", "Name", "Category", "Expired_date", "Stock");
	while(scanf("%d %s %s %d %d", &record.id, record.name, record.category, &record.date, &record.stock) == 5){
		lseek(fd, record.id * sizeof(record), SEEK_SET);
		write(fd, (char *)&record, sizeof(record));
	}
	close(fd);
	exit(0);
}
		

