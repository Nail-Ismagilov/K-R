#include "exercise.h"
#include <ctype.h>
//#include <stdio.h>

double atof(char s[]){
    double val, power, exp = 1.0;
    int i, sign, eSign, ePos;
    char sci_n[3] = {'e','-','\0'};
    char sci_p[3] = {'e','+','\0'};

    if (strrindex (s, sci_p)) // sign of scientific notation
	    eSign = 1;
    else if (strrindex (s, sci_n))
	    eSign = -1;
    else
	    eSign = 0;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
	    ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
	    i++;
    for (val = 0.0; isdigit(s[i]); i++)
	    val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
	    i++;
    for(power = 1.0; isdigit(s[i]); i++) {
	    val = 10.0 * val + (s[i] - '0');
	    power *= 10;
    }

    if (eSign == -1){
	    i += 2;
	for(; (s[i]-'0') > 0; s[i]--)
		exp /= 10.0;
    }
    else if(eSign == 1){
        i += 2;
        for(; (s[i]-'0')>0; s[i]--)
		exp *= 10.0;
    }

    //printf("eSign =: %d \ni = %d\n", eSign, i);

    return (sign * val / power * exp);
}
