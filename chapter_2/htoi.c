#include <stdio.h>
#include <ctype.h>
#define MAX_LINE   100


/*hex_to_int converting hexidecimal 0..F from given string s to integer*/
long long int hex_to_int(char s[], int loc){
    long long int n;

    n = 0;
    for (loc; s[loc]>='0' && s[loc] <= '9' || tolower(s[loc])>='a' && tolower(s[loc])<='f'; loc++) { 
        if (s[loc]>='0' && s[loc] <= '9')
            n = 16 * n + (s[loc] - '0');
	else
	    n = 16 * n + 10 + (tolower(s[loc]) - 'a');	
    }
	
    return n;	
}

/*checking if the given number is hex starting with 0x or 0X*/
long long int htoi (char s[]){
    long long int n = 0;
    int i = 0;
    
    for(i=0;s[i] != '\0' && s[i] != EOF ; i++)
	  if (tolower(s[++i])=='x')		// Calls hex to int converter
		  return hex_to_int(s, ++i);
    return 0;
}

/*printing a giving array to the terminal*/
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

    while ((c = getchar()) != 'N' && c != '\n' && i < MAX_LINE){
	s[i] = c;
	++i;
    }
    
    s[i] = '\0';

    printf("array s:\n");
    print_array(s);					// Printing given array/Hexadecimal
    printf("converted to htoi: %lli\n", htoi(s));	// printing converted Hexadecimal to Integer

    return(0);
}
