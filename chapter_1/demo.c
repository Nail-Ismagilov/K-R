#include <stdio.h>

int main()
{

    int c;
    
    while ((c = getchar()) != EOF ) {
	putchar(c);
	printf("\n The value of the expression: %d\n", (getchar() != EOF));
    }    

    return(0);
}
