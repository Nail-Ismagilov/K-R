#include <stdio.h>

#define IN			1	// inside the word
#define OUT			0	// Outside the word
#define MAX_WORD_LENGTH 	20	// Maximum word length
int main()
{
    int c, i, nc, state;
    int frequency[MAX_WORD_LENGTH];
    state = IN;

    /* initializing the array ints to zero*/
    for (i = 0; i < MAX_WORD_LENGTH; ++i)
	frequency[i] = 0;
	
    i = nc = 0;
    while ((c = getchar()) != '0'){
	
    	if (((c >= 65) && (c <= 90)) || ((c >= 97 ) && (c <= 122))) {
    	    ++nc;
	}		
	else {
	    ++frequency[nc-1];
	    nc = 0;
	}
    }

    for (i = MAX_WORD_LENGTH-1; i >= 0; i--) {
	printf ("%2d    %2d|  ", frequency[i],i+1);
	for (;frequency[i] > 0; frequency[i]--)
	    printf("#");
	printf("\n");
    }
    printf("Freq  WL\n");

}
