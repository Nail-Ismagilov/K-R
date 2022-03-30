#include <stdio.h>
#define MAX_LINE   100

long long int atoi (char s[]){
    long long int n = 0;
    int i = 0;
    for(i=0; s[i]>='0' && s[i] <= '9'; i++)
	    n = 10 * n + (s[i] - '0');
    return n;
}

void print_array(char arr[]){
    int i;
    for(i = 0; arr[i] != '\0'; ++i)
	    printf("%c", arr[i]);
    printf("\n\n");
}

int main(){
    char s[MAX_LINE];
    
    int c = 0;
    int i = 0;
    while ((c = getchar()) != 'E' && c != '\n' && i < MAX_LINE){
	s[i] = c;
	++i;
    }
    s[i] = '\0';

    printf("array s:\n");
    print_array(s);
    printf("converted to atoi: %lli", atoi(s));
    //for 

    return(0);
}
