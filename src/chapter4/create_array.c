#include <stdio.h>


void print_array(char const arr[])
{
	int i;
	printf("+++The given array: ");
	for (i = 0; arr[i] != '\0'; i++)
		printf("%c", arr[i]);
	printf("\n");
}

void getarray (char s[], int lim){
	int i;
	char c;

	for (i=0; i < lim-1 && (c = getchar()) != '\n'; i++){
	s[i] = c;
	}

	s[i] = '\0';
	
	print_array(s);
}	
