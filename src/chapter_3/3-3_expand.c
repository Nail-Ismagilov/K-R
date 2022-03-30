#include <stdio.h>
#include <ctype.h>
#define SIZE 		200
#define MAX_SIZE 	20


void expand(char s1[], char s2[]){
	int i, j, count;
	j = 0;
	for(i=0; s1[i]!='\0'; i++) {
		//printf("%c\n",s1[i]);

		if (s1[i] >= '0' && s1[i] <= '9' &&
				s1[i+2] >= '0' && s1[i+2] <= '9'){
			
			printf("numbers %c...%c: ", s1[i], s1[i+2] );
			for(count = 0; s1[i]+count <= s1[i+2]; count++){
				s2[j] = s1[i]+count;
				printf("%c ", s2[j]);
				j++;
			}
			i++;	
			printf("\n");
		}

		else if (s1[i] >= 'a' && s1[i] <= 'z' && 
				s1[i+2] >= 'a' && s1[i+2] <= 'z') {

			printf("letters %c...%c: ",  s1[i], s1[i+2]);
			for(count = 0; s1[i]+count <= s1[i+2]; count++){
				s2[j] = s1[i]+count;
				printf("%c ", s2[j]);
				j++;
			}	
				
			i++;
			printf("\n");	
		}		

	}
	
	s2[j] = '\0';

}


int main()
{
	char s2[SIZE];
	int i;
	char s1[SIZE] = {'-', 'a', '-', 'z', '0', '-','9','c', '-', 'e', '-', 'g', '-', 'm','\0'};
	expand(s1, s2);
	
	for (i=0; s2[i] != '\0'; i++)
		printf("%c ", s2[i]);
	return(0);
}

