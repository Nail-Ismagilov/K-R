#include <stdio.h>
#include <string.h>
#include "chapter5.h"
#define MAXLINE     1000


int read_file(char *lineptr[], char file_name[])
{
    char line[MAXLINE];
    char *p;
    int len, nlines = 0;
    FILE * filep;
    filep = fopen(file_name, "r");
    // printf("read file %s.\n", file_name);
    
    if (filep != NULL)
    {
        
        while ((len = getline(filep, line, MAXLINE)) > 0)               // copies a line from "filep" into "line"
        {
             p = alloc(len);                                            // allocates p. initializing of p

                line[len-1] = '\0';                                     // get rid of a new line character '\n'
                strcpy(p, line);                                        // copy string from the array to apointer
                lineptr[nlines++] = p;                                  // assign the pointer into array of pointers
                // printf("line: %s\n", lineptr[nlines-1]);
                // printf("read file. nlines = %d\n", nlines); 
                if (feof(filep))
                    break;

        }
    }
    else    
        printf("could not open file: %s", file_name);
    fclose(filep);
// printf("lineptr[0]: %s\n", lineptr[0]);
// printf("lineptr[1]: %s\n", lineptr[1]);
// printf("lineptr[2]: %s\n", lineptr[2]);
    return nlines;
}


int getline(FILE * file, char s[], int lim){
    char c;
    
    int i;

    // printf("I am in getline\n");

    // Getting characters from the line till end of file 
    // or end of the line
    for (i=0; (c = fgetc(file)) != EOF && i < lim; ++i)    
    {
        s[i] = c;
        if (c == '\n') 
        {
            s[i] = c;
            i++;
            break;
        }
    }

    return i;
}

void print_tail(int nlines, int number, char ** lineptr)
{
    /*
        1. check igf the number of lines greater than a given number
        2. print the tail of the text
    */
    int tail = number;
    if (nlines < number)
        tail = nlines;

    for (int i = nlines - tail; i < nlines; i++)
        printf("%s\n", lineptr[i]);
        

}