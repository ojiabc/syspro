#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
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
    printf("input goods category:");
    char category[30];
    scanf("%s", category);
    printf("%-3s %-20s %-20s %-12s %-8s\n", "ID", "Name", "Category", "Expired_date", "Stock");
	int count = 0;
    while(id <= 999){
        lseek(fd, (id) * sizeof(record), SEEK_SET);
        if((read(fd, (char*)&record, sizeof(record)) > 0)&&record.date != 0){
            if(strcmp(category, record.category) == 0){
				printf("%-3d %-20s %-20s %-12d %-8d\n", record.id, record.name, record.category, record.date, record.stock);
				count++;
			}
        }
		id++;
    }
	if(count == 0)printf("not found goods category : '%s'\n", category);
    close(fd);
    exit(0);
}
