#define BUFFSIZE 100

char buf[BUFFSIZE]; /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch ()
{
    return (bufp > 0) ? buf[--bufp] : getch();
}

void ungetch(int c)
{
    if (bufp >= BUFFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}