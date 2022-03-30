#include <stdio.h>
#define MAXLINE		1000 /*maximum input line size*/
#define BLANK		0
#define NOT_BLANK	1

int getlines(char line[], int limit);
void deleteTrailingSpace(char array[], int position);
int checkTrailingSpace(char array[], int length);
int checkBlank(char array[], int length);
void reverse(char array[]);

int main()

{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 80;
    while ((len = getlines(line, MAXLINE)) > 0)
    
    {

	len = checkTrailingSpace(line, len);
	if (checkBlank(line, len)) {
		reverse(line);
		printf("%s", line);
    	}
    }
	
    if (max > 0)
	printf("%s", longest);
    
    return(0);
}

int checkTrailingSpace(char s[], int length) {
    int new_length, i;

    new_length = length;
    for (i = 0; i < length; i++ ) {
	    if (((s[i] == ' ') && (s[i+1] == ' ')) || ((s[i] == '\t') && (s[i+1] == '\t'))) {
		deleteTrailingSpace(s, i);
		--new_length;
		--i;
	    }
    }

    return new_length;
}

void deleteTrailingSpace (char c[], int i) {
    for(; c[i]!='\0'; i++)
	c[i] = c[i+1];
}

int checkBlank(char s[], int length) {
    int c, i;
    c = 0;
    for (i=0; i<length; i++) {
	if (s[i]!='\n' && s[i]!=' ' && s[i]!='\t' && s[i]!=EOF)
		++c;	
    }
    if (c==0)
	return BLANK;
    else 
	return NOT_BLANK;

}

int getlines(char s[], int lim){
    int c, i;

    for (i=0; (c=getchar()) !=EOF && c!='\n'; ++i)    
	s[i] = c;
    if (c == '\n') {
	s[i] = c;
	++i;
    }

    s[i] = '\0';
    
    return i;
}

void reverse(char s[]) {
    int i,c;
    char temp;
    for (i=0; s[i]!='\0'; ++i) {}

    for (c=0; c<(i/2); ++c){
        temp = s[c];
        s[c] = s[i-c-2];
	s[i-c-2] = temp;
    }
}
