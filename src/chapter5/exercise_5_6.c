#include <stdio.h>

int getlines(char *s){
    int c, length = 0;

    while ((c=getchar()) !=EOF && c!='\n') 
    {    
    	*s = c;
        s++; length++;
    }    

    /*check if new line*/       
    if (c == '\n') {
	    *s = c;
	    s++; length++;
    }

    *s = '\0';
    return length;
}

void mygetline(char s[], int lim) {

	int c, length = 0;

	for (; length < lim && (c = getchar()) != '\n' && c != EOF; s++, length++)
		*s = c;

	*s = '\0';
}

long long int atoi (char *s){
    long long int n = 0;
    for(; *s >='0' && *s <= '9'; s++)
	    n = 10 * n + (*s - '0');
    return n;
}



void reverse(char *s)
{
	int length;
	char *t;

	for (length = 0; *s!= '\0'; length++, s++)
        ;
	for (; 0 < length; length--, s--, t++) {
	    *t = *s;
	}

    s = t;
}