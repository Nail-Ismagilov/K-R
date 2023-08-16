#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE	40


void reverse (char *s, int, int);
void getarray (char s[], int lim);
void print_array(char arr[]);
void itob(long int, char *, int);

int main()
{
	char r[SIZE] = "HELLO\0";
	char s[SIZE];
	int i = -74856;

	printf("Array before reverse: ");
	printf("\n");
	//print_array(s);
	itob(i, s, 12);
	printf("\n");
	print_array(s);

	return (0);
}


void print_array(char arr[])
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

/* reverse: reverse elements of string s */
void reverse(char s[], int left, int length)
{
	char temp;

	

	if (length > left) {
		// printf("\n reverse loop: iteration N%d", left); //Debugging: check if if condition work
		temp = s[left];
		s[left] = s[length];
		s[length] = temp;
		reverse (s, ++left, --length);
	}

	

}

/* itob: convert n to characters in s */
void itob(long int n, char s[], int b)
{
	int i; 
	long sign;
	int length;
	printf("\n %ld \n", n);   	// debugging, print befor n * (-1)
	if((sign = n) < 0)
		n = -n;
	i = 0;
	printf("\n %ld \n", n);	// debugging: print after n * (-1)

	
	/*checks if the reminder less then 10 or greater and assigned digit or letter correspondingly*/
	do {	
		if (n % b < 10)
			s[i++] = n % b + '0';
		else if ( n % b < 16) {
			s[i++] = (n % b) % 10 + 'A';
			printf("%ld\n", (n % b));
		}
		else {
			printf("Wrong number... Terminating at %d iteration", i);
			break;
			}
	} while ((n /= b) > 0);

	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	for (length = 0; s[length] != '\0'; length++) {}
	// print_array(s); // debugging: Check if the itob works
	
	reverse(s, 0 ,length-1);
	// print_array(s);
	
}
