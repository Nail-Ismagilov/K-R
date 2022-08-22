#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "exercise.h"

#define SIZE	40


int main()
{
	char s[SIZE] = "HELLO\0";

	printf("Array before reverse: ");
	printf("\n");
	print_array(s);
	reverse(s);
	printf("\n");
	print_array(s);

	//printf("reverse Polish calculator start...\n");
	//revPolish();

	//printf("---Hello\n---give me the first array: " );
	//getarray(s, SIZE);

	//printf("give me the second sequence: ");
	//getarray(t, SIZE);


	//i = strrindex(s,t);
	//printf("'t' meets 's' in position %d\n", i);

	// d = atof(s);
	// printf("The double is: %f\n", d);
	// start of reverse polish calculator
	return (0);
}
