#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include "item.h"
#define MAX_ID 999
int main(int argc, char*argv[]){
    int fd;
    struct item record;
    if(argc != 2){
        fprintf(stderr, "How to use: %s file\n", argv[0]);
        exit(1);
    }
    if((fd = open(argv[1], O_RDWR)) == -1){
        perror(argv[1]);
        exit(2);
    }
    printf("(n): sell one goods:");
    int id;
    scanf("%d", &id);
	lseek(fd, (id) * sizeof(record), SEEK_SET);
	if((read(fd, (char*)&record, sizeof(record)) > 0)&&record.date != 0){
		if(record.stock > 0 && record.date >= 2024){
			record.stock--;
			lseek(fd, (id) * sizeof(record), SEEK_SET);
			write(fd, (char *)&record, sizeof(record));
			printf("'%s'(%d) has been sold out...", record.name, record.id);
			if(record.stock == 0)printf("(There is no stock)");
			printf("\n");
		}
		else{
			printf("'%s' is cannot be sold\n", record.name);
		}
	}
    printf("%-3s %-20s %-20s %-12s %-8s\n", "ID", "Name", "Category", "Expired_date", "Stock");
	id = 0;
    while(1){
        id++;
        lseek(fd, (id) * sizeof(record), SEEK_SET);
        if((read(fd, (char*)&record, sizeof(record)) > 0)&&record.date != 0){
            printf("%-3d %-20s %-20s %-12d %-8d\n", record.id, record.name, record.category, record.date, record.stock);
        }
        else if(id > MAX_ID)  break;
    }
    close(fd);
    exit(0);
}