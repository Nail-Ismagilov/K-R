#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "chapter6.h"



int getword(char *word, int lim, char * file_name)
{
    printf("I am in the getword....\n");
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    // FILE * filep;
    // filep = fopen(file_name, "r");

    while (isspace(c = fgetc(filep)))
        ;
    if (c != EOF)
        *w++ = c;
    if ( !isalpha(c))
    {
        *w = '\0';
        return c;
    }

    for( ; --lim > 0; w++)
        if(!isalnum(*w = fgetc(filep)))
        {
            ungetc(*w, filep);
            break;
        }
    *w = '\0';
    for (int i=0; word[i] != '\0'; i++)
        printf("%c", word[i]);
    printf("\n");
    fclose(filep);
    return word[0];

}

int binsearch(char *word, struct key tab[], int n)
{
    printf("enter binsearch...\n");
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
    
}

