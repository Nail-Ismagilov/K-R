#define SIZE 		20
#define MAX_SIZE 	200
#define INT_MIN		-2147483648

/* reverse: reverse elements of string s */
void reverse(char s[])
{
	int length, i;


	for (length = 0; s[length] != '\0'; length++) {}
	for (i = 0, length-- ; i < length; i++, length--) {
		char temp = s[i];
		s[i] = s[length];
		s[length] = temp;
	}

}

/* itoa: convert n to characters in s */
void itob(long int n, char s[], int b)
{
	int i; 
	long sign;

	// printf("\n %ld \n", n);   	// debugging, print befor n * (-1)
	if((sign = n) < 0)
		n = -n;
	i = 0;
	// printf("\n %ld \n", n);	// debugging: print after n * (-1)

	
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
	reverse(s);
	
}
