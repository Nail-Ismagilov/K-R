#include <stdio.h>


int main()
{
    int a;
    char c;
    float f;
    double d;
    
    printf("integer has size: %li bytes\n", sizeof(a));
    printf("char has size: %li byte\n", sizeof(c));
    printf("float has size: %li bytes\n", sizeof(float));
    printf("double has size: %li\n", sizeof(double));
    printf("long double has size: %li\n", sizeof(long double));

    

    return (0);
}
