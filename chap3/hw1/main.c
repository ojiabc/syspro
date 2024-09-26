#include <stdio.h>
#include <string.h>
char line[5][100];
char len[5];
int main()
{
    int i = 0;
    while(i<5){
        gets(line[i]);
        len[i]=strlen(line[i]);
        i++;
    }
    i = 0;
    while(i<5){
        int j = 0;
        int maxLen = 0;
        int maxLenLine = 0;
        while(j<5){
            if(maxLen<len[j]){
                maxLen=len[j];
                maxLenLine=j;
            }
            j++;
        }
        len[maxLenLine]=-1;
        printf("%s\n",line[maxLenLine]);
        i++;
    }

    return 0;
}
