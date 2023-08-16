#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "chapter5.h"
#include "exercise.h"

#define MAXLINE    1000
#define MAXLINES   1000
#define MAX_LENGTH 50
#define SIZE       20


/* tail -n: print last n lines of a file. n as default 10*/
int main(int argc, char *argv[])
{
    char * lineptr[MAXLINES];

    char * c, * file;
    char filePattern[] = ".txt";
    int number = 10, nlines;
    int test = -1;
        



    while (--argc > 0 )
    {
        // strcpy(*line, *argv);
        // printf("argc = %d\n", argc);
        // printf("argv: %s\n", *argv);

        if (**++argv == '-')
        {   c = *argv;
            number = atof(c);
            if (number < 0)
                number = -number;
        }
        
        else if ((test = strend(*argv, filePattern)))
        {    
            file = *argv;
            // printf("found a file %s\n", file);
            nlines = read_file(lineptr, file);
        }    
    }

    print_tail(nlines, number, lineptr);

    return 0;
}

