
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

enum {KEYWORD = 0, STRING, COMMENT, MULTIPLE_LINE_COMMENT, NOT_DEFINED};

/* binsearch: find word in tab[0]..tab[n-1] 
 * strcat: ccontantenate t to end of s; s must be big enough
 * @word a character, that should be checked 
 *             wheter is digit or not
* @tab[] an array of structure storing a word and integer number
 * @n    is a size of the tab array   
 */
int binsearch(char * word, struct key tab[], int n);

struct key * pbinsearch(char * word, struct key * tab, int n);
/* pbinsearch: is a pointer version ofbinsearc 
 * strcat: ccontantenate t to end of s; s must be big enough
 * @word a character, that should be checked 
 *             wheter is digit or not
 * @tab is a apointer to structure key
 * @n    is a size of the tab array   
 * return: pointer to a strucure type key
 */


/* getword: get neyt word or c*/
int getword(char *, int, FILE *);

/* getchf: get a character from a file 
 * @file is a file from the chracter has to be read*/
char getchf(FILE * file);

/* ungetchf: store the character in a buffer
 * @c the character which has to be stored */
void ungetchf(char c);

/* setstatus: sets a status of a current code part
 *
 * @n is a current character came from the reading file
 * @precChar is a previous character
 * @token is a current status which should be changed or not
 * */
void setstatus(int n, int *prevChar, int *token);

#endif