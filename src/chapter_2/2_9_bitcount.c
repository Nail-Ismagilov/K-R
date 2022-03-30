#include <stdio.h>

int bitcount(unsigned x) {
	int b;

	for (b=0; x!=0; x &= x-1, b++) {}
	/*for (b = 0; x != 0; x >>= 1){
		if (x & 01) b++;
		printf ("%d\n", x);
	}*/
	return b;
}

int main()
{
	int x = 0xFF;
	
	printf("%d has %d '1' bits", x, bitcount(x));
	return(0);
}

