#include <stdio.h>


#define    LOWER    0       /* lower limit of table */
#define    UPPER    300     /* upper limit */
#define    STEP     20      /* step size */

int power(int, int);
float fahrenheitToCelcius(int);


int main() 
{
    int i;
    int fahr;

    for (i = 0; i < 10; i++) 
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
   
    
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
	printf("%3d %6.1f\n", fahr, fahrenheitToCelcius(fahr));

    return (0);
}


int power(int n, int m) {
    int np = 1;

    for (int i = 0; i < m; i++)
	np *= n;

    return np;
}


float fahrenheitToCelcius(int fahr) {
    
    return((5.0/9.0)*(fahr-32));
}
