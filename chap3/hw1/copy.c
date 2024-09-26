#include <stdio.h>
/* copy: copying the from to the to; consist to is big enough*/

void copy(char from[], char to[]){
	int i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
