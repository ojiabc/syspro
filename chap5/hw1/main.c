#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include<unistd.h>
#define MAX 1000

char text[MAX][MAX];
void print_line(int line){
    char c = 'a';
    int i = 0;
    while (c != '\0' && c != '\n' && i < MAX){
        c = text[line][i];
        printf("%c", c);
        i++;
    }
}

int main(int argc, char *argv[]) 
{
    int fd;
    char buffer;
    if (argc < 2)
    {
        fprintf(stderr, "How to use: %s target_file\n", argv[0]);
        exit(1);
    }
    if ((fd = open(argv[1], O_RDWR)) == -1)
        perror(argv[1]);
    
    int line = 0, pos = 0;
    while(read(fd, &buffer, 1) > 0)
    {
        text[line][pos] = buffer;
        pos++;
        if(buffer == '\n')
        {
            line++;
            pos = 0;
        }
    }
	printf("choose lines (1~%d):", line);
    char command[100];
    fgets(command, 100, stdin);
    int start_num = 0, end_num = 0, found_dash = 0;
    char c = 'a';
    int c_i = 0;
    while (c != '\0' && c != '\n' && c_i < 100)
    {
        c = command[c_i];
        if (c >= 48 && c <= 57)
        {
            if (found_dash == 0)
            {
                start_num *= 10;
                start_num += (c - 48);
            }
            else
            {
                end_num *= 10;
                end_num += (c - 48);
            }
        }
        else if (c == '-')
        {
            found_dash = 1;
        }
        else if (c == ',')
        {
            print_line(start_num - 1);
            start_num = 0;
        }
        c_i++;
    }
    if (found_dash == 0)
    {
        print_line(start_num - 1);
    }
    else
    {
        for(int i = start_num; i <= end_num; i++)
        {
            print_line(i - 1);
        }
    }
    close(fd);
    exit(0);
}
