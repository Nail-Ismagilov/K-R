#include <stdint.h>
int8_t strrindex (char s[], char t[]){
	int j, k;
	int rPos = 0;

	// Test
	for (int i = 0; s[i] != '\0'; i++){
		for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++ )
			;
		if (k > 0 && t[k] == '\0')
			rPos = j - k;

	}

	/*for (int i = 0; s[i] != '\0'; i++){
		for (j = rPos; t[j] != '\0'; j++ )
			if ((s[i] == t [j]) && (j > rPos))
				rPos = j;
	}*/

	if(rPos == 0)
		return 0;


	return rPos;
}
