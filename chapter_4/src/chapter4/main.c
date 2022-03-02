#include <stdio.h>
#include <stdint.h>
#include "exercise.h"

#define SIZE	40


int main()
{
	char s[SIZE], t[SIZE];
	int8_t i;
	printf("Hey give me the first sequnce: " );
	getarray(s, SIZE);

	printf("give me the second sequence: ");
	getarray(t, SIZE);

	
	i = strrindex(s,t);
	printf("'t' meets 's' in position %d\n", i);	
	
	return (0);
}
