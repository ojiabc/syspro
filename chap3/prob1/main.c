#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE]; // input line
char longest[MAXLINE]; // longest line
/* print he longest line in input lines*/

int main(){
	int len;
	int max;
	max = 0;

	while(gets(line) != NULL){
		len = strlen(line);

		if(len > max) {
			max = len;
			copy(line, longest);
		}
	}
	if (max > 0) // input line exist
		printf("%s \n", longest);
	
	return 0;
}
