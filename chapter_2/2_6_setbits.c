#include <stdio.h>

/*print_bits: converts decimal to binary*/
void print_bits(int x);

/*setbits: sets n bits of x started from p position to beginning of y*/
unsigned setbits(unsigned x, int p, int n, unsigned y);

/*invert: inverts n bits of x starting from p position*/
unsigned invert(unsigned x, int p, int n);

int main() 
{
	int x = 0x1;
	int y = 0x0;
	int p = 9;
	int n = 8;

	// print_bits(1u << 0);
	// print_bits(x);
	// print_bits(y);
	
	printf("set x bits to y\n");
	print_bits(setbits(x,p,n,y));

	printf("invert x\n");
	print_bits(invert(x, p, n));	
	return(0);
}

unsigned setbits (unsigned x, int p, int n, unsigned y) {
	return (y & (~0 << n)) | (x >> (p + 1 - n)) & ~(~0 << n);
}


unsigned invert (unsigned x, int p, int n) {
	int a, i;
	a = (~(x >> (p + 1 - n)) & ~(~0 << n)) << (p + 1 - n);	
	
	print_bits(x);
	
	for( i = p+1; i >= p+1-n; i--) {
		x &= ~(1u << i);
	}
	
	return (x | a);
}

void print_bits(int x) {
	int i;
	printf("%d in bits: \t", x);
	for (i = sizeof(int)*8 - 1; i >= 0; i--)
		printf("%c", (x & (1u << i) ) ? '1' : '0');
	printf("\n");
}

