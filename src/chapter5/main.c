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

    while(--argc > 0 && (*++argv)[0] == '-')
    {
        while (c = *++argv[0])
        {
            switch (c){
                case 'x':
                    except = 1;
                    printf("find: legal option %c\n", c);
                    printf("find: except %d\n", number);
                    break;
                case 'n':
                    number = 1;
                    printf("find: legal option %c\n", c);
                    printf("find: number %d\n", number);
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }               

    if(argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while (getlines(line, MAXLINE) > 0)
            lineno++;
            if ((strstr(line, *argv) != NULL) != except){
                if (number)
                    printf("lineno: %ld\n", lineno);
                printf("line: %s\n", line);
                found++;
            }

    printf("Number of equality: %d", found);

    return found;
}

