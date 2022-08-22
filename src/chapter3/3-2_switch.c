#include <stdio.h>

#define SIZE 		20
#define MAX_SIZE 	20

void escape(char s[], char t[]){
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++, j++) {
		switch (s[i]){
			case '\n':
				t[j++] = '\\';
				t[j] = 'n';
				break;
			case '\t':
				t[j++] = '\\';
				t[j] = 't';
				break;
			default:
				t[j] = s[i];
				break;
		}
		printf("%c", s[i] );
	}
	t[j] = '\0'; 
	printf("\n\n");
	for (i=0; t[i] !='\0'; i++)
		printf(" %c", t[i]);
}	

void enter(char s[], char t[]){

	int i, j;

	printf("\n\n");
	for (i = j = 0; s[i] != '\0'; i++, j++) {
		switch (t[j]){
			case '\\':
			       switch (t[++j]){
					case 'n':
						s[i] = '\n';
						break;
					case 't':	
						s[i] = '\t';
						break;
					default:
						s[i] = t[--j];
			       }		break;
	       			break;		       
				
			default:
				s[i] = t[j];
				break;
		}
		printf("%c", s[i] );
	}
	s[i] = '\0'; 

	//for (i=0; t[i] !='\0'; i++)
}

int main()
{

	char t[MAX_SIZE];
	int i;
	char  s[SIZE] = {'1', '2', '3', '\n', '\n', '\t', '7', '\t', '9'};
	/*for (i = 0; i < 9; i++) {
		s[i] = 'a' + i;
	}

	s[10] = '\0';
	*/
	escape(s, t);
	enter(s, t);
/*
	int c, i, nwhite, nother, ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; i++)
		ndigit[i] = 0;
	while ((c = getchar()) != 'N') {
		switch (c) {
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6':  case '7': case '8': case '9':
				ndigit[c-'0']++;
				break;
			case' ':
			case '\n':
			case '\t':
				nwhite++;
				break;
			default:
				nother++;
				break;
		}
	}

	printf("digits =");
	for (i = 0; i  < 10; i++)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
*/
	return(0);
}

