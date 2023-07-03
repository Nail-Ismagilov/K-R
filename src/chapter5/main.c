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



int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;

    if(argc != 2)
        printf("Usage: find pattern\n");
    else
        while (getlines(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL){
                printf("%s", line);
                found++;
            }
    printf("Number of equality: %d", found);
    return 0;
}

