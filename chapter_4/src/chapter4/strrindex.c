#include <stdint.h>
int8_t strrindex (char s[], char t[]){
	int i, j, k;
	int rPos = 0;
	for (int i = 0; s[i] != '\0'; i++){
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++ )
			rPos = i;
	}
	
	if(rPos == 0)
		return -1;
	
	
	return rPos;
}
