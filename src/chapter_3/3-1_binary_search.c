#include <stdio.h>

#define SIZE 100000

int binsearch(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;

	/*printf("low \thigh \tmid\tx = %d\n",x);
	while (low <= high) {
		mid = (low + high) / 2;
		if (x <= v[mid])
			high = mid -1;
		else 
			low = mid + 1;
		printf("%3d \t%3d \t%3d\n", low, high, mid);
	}

	if (x == v[low])
		return mid;
	else
		return -1;
	*/
	printf("is %d less than %d: %c\n",x,v[6], (x < v[6])? 'Y':'N');
	printf("low \thigh \tmid\tx = %d\n",x);
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
		printf("%3d \t%3d \t%3d\n", low, high, mid);
	}

	return -1;
}

int main()
{
	int i, a[SIZE], x;

	for(i = 0; i < SIZE; i++) {
		a[i] = i;
//		printf("%3d ", a[i]);
	}

	printf("\n");
	x = 12431;

	printf("The positioni of %d is %d\n",x, binsearch(x, a, SIZE ));
	
	return(0);
}

