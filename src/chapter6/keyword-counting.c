#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "chapter6.h"

#define BUFFSIZE    100

char buf[BUFFSIZE]; /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */



int getword(char *word, int lim, FILE * filep)
{
    // printf("I am in the getword....\n");
    int c;
    char *w = word;
    while (isspace(c = getchf(filep)))
        ;
    if (c != EOF)
        *w++ = c;
    if ( !isalpha(c) )
    {
        if(c != '#' || c != '/')
        {
            *w = '\0';
            return c;
        }
    }

    for( ; --lim > 0; w++)
    {
        if(!isalnum(*w = getchf(filep)))
        {   
            if(*w != '*')
            {
                ungetchf(*w);
                break;
            }
        }

    }
    *w = '\0';

    if (word[0] == '#')
        for(int i = 0; word[i] != '\0';i++)
            word[i] = word[i+1];

    // printf("\n"); 
    return word[0];

}

int binsearch(char *word, struct key tab[], int n)
{
    // printf("enter binsearch...\n");
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        // printf("word: %s\ntab.word: %s\n", word, tab[mid].word);
        // printf("Is word and tab.word equal: %s\n", (strcmp(word, tab[mid].word)) ? "NO" : "YES" );
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
    
}


struct key * pbinsearch(char * word, struct key * tab, int n)
{

    int cond;


    struct key *high = &tab[n];
    struct key *low = &tab[0]; 
    struct key *mid;


    while (low < high)
    {
        mid = low + (high-low) / 2;
        // printf("word: %s\ntab.word: %s\n", word, tab[mid].word);
        // printf("Is word and tab.word equal: %s\n", (strcmp(word, tab[mid].word)) ? "NO" : "YES" );
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
    
}



char getchf(FILE * file)
{
    return (bufp > 0) ? buf[--bufp] :  fgetc(file);
}

void ungetchf(char c)
{
    if (bufp >= BUFFSIZE)
        fprintf(stderr, "ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}