#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include "item.h"
#define MAX_ID 999
int main(int argc, char*argv[]){
    int fd, id = 0;
    struct item record;
    int ids[MAX_ID];
	int date[MAX_ID];
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
	 int i = 0, n = 0;
    while(1){
        id++;
        lseek(fd, (id) * sizeof(record), SEEK_SET);
        if((read(fd, (char*)&record, sizeof(record)) > 0)&&record.date != 0){
            ids[i] = record.id;
				date[i] = record.date;
				n++;
        }
        else if(id > MAX_ID) break;
    }	 
    int max = date[0];
	int start = 0;
	while(start + 1 < n){	
		int k = 0;
	 	while(k + 1 < n) {
			if(date[k] < date[k+1]){
				int tmp = date[k];
				date[k] = date[k+1];
				date[k+1] = tmp;
				tmp = ids[k];
				ids[k] = ids[k+1];
				ids[k+1] = tmp;
			}
			k++;
		}
	}
	int m = 0;
    while(m < n){
        m++;
        lseek(fd, (ids[m]) * sizeof(record), SEEK_SET);
        if((read(fd, (char*)&record, sizeof(record)) > 0)&&record.date != 0){
            if(command == 1 && record.stock == 0)continue;
            printf("%-3d %-20s %-20s %-12d %-8d\n", record.id, record.name, record.category, record.date, record.stock);
        }
    }
    close(fd);
    exit(0);
}
