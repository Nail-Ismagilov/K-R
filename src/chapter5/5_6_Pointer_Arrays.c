/*This module is about to colying functions from the 
 * chapter 5.6 to deeply understand it. 
*/
#include <stdio.h>
#include <string.h>
// #include "..\..\includes\chapter5\chapter5.h"

#define MAXLINES    5000    /* max #lines to be stored */
#define MAXLEN      1000    /* max length of any line */
//char *lineptr[MAXLINES];


char *alloc(int);


// int main()
// {
//     int nlines; /* number of input lines read */

//     if ((nlines = readLine(lineptr, MAXLINES)) >= 0){
//         qsort(lineptr, 0, nlines-1);
//         writeLines(lineptr, nlines);
//         return 0;
//     }
//     else
//     {
//         printf("error: input too big to sort");
//         return 1;
//     }

// }

int getlines(char s[], int lim){
    int c, i;

    // Getting characters from the line till end of file 
    // or end of the line
    for (i=0; (c=getchar()) !=EOF && c!='q' && i < lim; ++i)    
        s[i] = c;
    
    if (c == '\n') 
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    if ( i >= lim)
        i = -1;

    return i;
}

int readLine(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getlines(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else 
        {
            line[len-1] = '\0'; /* delete newline symbol*/
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return 0;
}


int writeLines(char *lineptr[], int nlines)
{
    int i;

    for(i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
    return i;
}
