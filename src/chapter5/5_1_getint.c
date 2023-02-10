#include <ctype.h>
#include <stdio.h>

int getch();
void ungetch(int);

int getint(int *pn)
{
    int c, sign, is_sign, signFlag;
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

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF)
    {
        ungetch (c);
    }
    return c;
}

