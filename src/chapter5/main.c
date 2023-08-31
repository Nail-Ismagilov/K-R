/*
 * The programm tail is showing last n given lines, and sorts the entire file alpha-/numerecly
 * command '-n': shows the last n lines of a file 
 * command '-f': foldable
 * command '-r': reverses the linse in the file allowing to show first n lines
 *
 */

#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "chapter5.h"
#include "exercise.h"

#define MAXLINE    1000
#define MAXLINES   1000
#define MAX_LENGTH 50
#define SIZE       20

char * lineptr[MAXLINES];                       /* pointers to text lines */
// int readlines(char *lineptr[], int nlines);
// void writelines(char *lineptr[], int nlines);

int numcmp(char *, char *);

/* sort input lines*/
int main(int argc, char *argv[])
{
    
    int numeric = 0, reverse = 0, foldable = 0;

    char *file;
    char filePattern[] = ".txt";
    int number = 100, nlines = 0;
    int i = 0;
        


    
    while (--argc >= 0 )
    {
   
        // printf("argv[%d]: %s\n", i, argv[i]);

        if (strcmp(argv[i], "-n") == 0)
        {
            numeric = 1;
        }
        else if ((strcmp(argv[i], "-r") == 0))
        {
    	    reverse = 1;
        }
        else if ((strcmp(argv[i], "-f") == 0))
        {
    	    foldable = 1;
        }    
        else if (strend(argv[i], filePattern) == 1)
        {    
            file = argv[i];
            //printf("found a file %s\n", file);
            nlines = read_file(lineptr, file);
            //print_tail(nlines, number, lineptr);
        }

        i++;
    }
    if (nlines >= 0)
        {            
            
            qsort((void **) lineptr, 0, nlines-1,
                    (int(*)(void *, void *))(numeric ? numcmp : (foldable ? strcmp_f : strcmp)), reverse); 
        }

    print_tail(nlines, number, lineptr);

    return 0;
}

