
#ifndef __CHAPTER6_H__
#define __CHAPTER6_H__

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD  100

struct key{
    char *word;
    int count;
} ;  


/* binsearch: find word in tab[0]..tab[n-1] 
 * strcat: ccontantenate t to end of s; s must be big enough
 * @word a character, that should be checked 
 *             wheter is digit or not
* @tab[] an array of structure storing a word and integer number
 * @n    is a size of the tab array   
 */
int binsearch(char * word, struct key tab[], int n);

/* getword: get neyt word or c*/
int getword(char *, int, char *);

#endif