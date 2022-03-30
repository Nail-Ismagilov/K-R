#include <stdio.h>

int main()
{
    int i, j,d,a;
    d=11;
    j = 0;
    for (i=0; i<10; i++,++j) {
	a = --d;
	printf("i++: %2d   ++j: %2d  a: %2d\n", i, j, a);

    }

    printf("i++: %2d   ++j: %2d\n", i, j);

    return(0);
}
