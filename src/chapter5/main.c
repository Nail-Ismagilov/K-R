#include <stdio.h>
#include <string.h>
#include "chapter5.h"

#define MAXLINE  1000
#define MAX_LENGTH 50
#define SIZE       20

void printString (char strin[])
{
    while(*strin != '\n')
    {
        printf("%c", *strin);
        strin++;
    }
}


/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;
    int i = 0;
    // char arr[MAX_LENGTH];
    // while(--argc > 0 && (*++argv)[0])
    // {
    //     while(c = *argv[0])
    //         {   
    //             printf("argv[%d]: %c\n", i, c);
    //             *++argv[0];
    //             arr[++i] = c;
    //         }
    // }
    // arr[i]='\0';         
    revPolish(argc, argv);
    return 0;
}

