#include <chapter6.h>
/* count C keywords*/
int main()
{
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if((n = binsearch(word, keytab, NKEYS)) >= 0)
            keytab[n].count++;
        for (n = 0; n < NKEYS; n++)
            if (keytab[n].count > 0)
                printf("%4d %s\n", 
                        keytab[n].count, keytab[n].word);
}