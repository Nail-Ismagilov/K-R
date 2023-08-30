#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "chapter6.h"

#define BUFFSIZE    100

char buf[BUFFSIZE]; /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */


int getword(char *word, int lim, FILE * filep, char *space)
{
    // printf("I am in the getword....\n");
    int c;

    char *w = word;
    while ((c = getchf(filep)) == ' ')
        *(space++) = c;
    *space = '\0';

    if (c != EOF)
        *w++ = c;

    if ( !isalnum(c) )
    {
        if(c != '_')
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

    // if (word[0] == '#' || word[0] == '_')
    if (word[0] == '_')                         /*define is not a  variable*/
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

void setstatus(int n, int const *prevChar, int *status)
{
    switch(n)
    {
        case '/':
            switch (*status)
            {
                case DEFINE:
                    *status = NOT_DEFINED;
                    break;
                case NOT_DEFINED:
                    if (*prevChar == '/')
                    {
                        *status = COMMENT;
                    }
                    break;
                case MULTIPLE_LINE_COMMENT:
                    if (*prevChar == '*')
                    {
                        *status = CODE;
                    }
                    break;
                case CODE:
                    *status = NOT_DEFINED;
                    break;
                default:
                    break;
            }
            break;
        case '*':
            switch (*status)
            {
                case DEFINE:
                    *status = NOT_DEFINED;
                    break;
                case NOT_DEFINED:
                    if (*prevChar == '/')
                    {
                        *status = MULTIPLE_LINE_COMMENT;
                    }
                    break;
                case CODE:
                    *status = CODE;
                    break;
                case  MULTIPLE_LINE_COMMENT:
                if (*prevChar != '/')
                    {
                        *status = MULTIPLE_LINE_COMMENT;
                    }
                    break;
                default:
                    break;
            }
            break;

        case '\"':
            switch (*status)
            {
                case DEFINE:
                    *status = NOT_DEFINED;
                    break;
                case CODE:
                    if (*prevChar != '\\')
                        *status = STRING;
                    break;
                case STRING:
                    if (*prevChar != '\\')
                        *status = CODE;
                    break;
                default:
                    break;
            }
            break;
        case '\n':
            switch (*status)
            {
                case DEFINE:
                    *status = CODE;
                    break;
                case COMMENT:
                    *status = CODE;
                    break;
                case STRING:
                case CODE:
                case MULTIPLE_LINE_COMMENT:
                default:
                    break;
            }
            break;
        case '#':
            switch (*status)
            {
                case CODE:
                    *status = DEFINE;
                    break; 
                case DEFINE:
                    *status = NOT_DEFINED;
                    break;
                case COMMENT:
                    break;
                case STRING:
                    break;
                case MULTIPLE_LINE_COMMENT:
                    *status = MULTIPLE_LINE_COMMENT;
                    break;
                default:
                    break;
            }
            break;
        default:
            if (NOT_DEFINED == *status)
                *status = CODE;
            break;
    }
}