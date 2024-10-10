#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
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
    printf("total lines: %d\n", line);
    while(line >= 0)
    {
        print_line(line);
        line--;
    }
    close(fd);
    exit(0);
}
