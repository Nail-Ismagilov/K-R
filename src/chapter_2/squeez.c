#include <stdio.h>

void squeez(char s1[], char s2[]);


int main()
{

char arr1[100] = {'a','b','r','c', 'a', 'a', 'a', 'o' ,'\0'};
char arr2[100] = {'a', 'c', 'd', 'e', '\0'};
squeez(arr1, arr2);


    return(0);
}


void squeez(char s1[], char s2[]) {
	int i, j, y;
	for(i=0; s2[i] != '\0'; i++){
	    for(j=0; s1[j] != '\0'; j++) {
			if(s1[j] == s2[i])
		    	for(y = j; s1[y] !='\0'; y++)
			s1[y] = s1[y+1];    
	    }

	}

	for(i=0; s1[i] != '\0'; i++)
	    printf("%c, ", s1[i]);
}
