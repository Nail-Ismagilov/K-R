#include "exercise.h"
#include <stdio.h>

#define SIZE	40


int main()
{
	char s[SIZE], t[SIZE];
	
	printf("Hey give me the first sequnce: " );
	getarray(s, SIZE);

	printf("give me the second sequence: ");
	getarray(t, SIZE);


	//strrindex(s,t);	
	return (0);
}
