#include <ctype.h>
#include <stdio.h>


char getfloat(char *pn){
    
    char c, sign, is_sign, signFlag;
    signFlag = 0;
    while (isspace(c = getch()))    /*skip white spaces*/
        ;
    if (isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);     /*it's not a number*/
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    /*Skipping the following signs*/
    while(c == '+' || c == '-')
        c = getch();

    *pn = sign;
    pn++;
    for (; isdigit(c) || c == "."; c = getch(), pn++)
    {
        *pn = c;
    }

    if (c != EOF)
    {
        ungetch (c);
    }
    return c;
}