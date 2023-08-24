
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

struct tnode{               /* the tree node: */
    char *word;             /* points to the text */
    int count;              /* number of occurences */
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
};

// struct word{                    /* words */
//     char *word;                 /* points to the string*/
//     struct word * leftWord;     /* left child */
//     struct word * rightWord;    /* right child */
// };

struct wordgroup{              /* group of words with same last 6 chars*/
    char *group;               /* points to the name of the group */
    struct tnode * word;        /* points to the words database */
    int count;                 /* counts number of words in the group*/
    struct wordgroup *left;    /* left child */
    struct wordgroup *right;   /* right child */
};

enum {KEYWORD = 0, STRING, COMMENT, MULTIPLE_LINE_COMMENT, NOT_DEFINED};

/* binsearch: find word in tab[0]..tab[n-1] 
 * \param char* word a string, that should be checked 
 *             wheter is digit or not
 * \param struct key tab[] an array of structure storing a word and integer number
 * \param int n    is a size of the tab array 
 * \return an index in tab or -1 if nothing found*/
int binsearch(char * word, struct key tab[], int n);

/* pbinsearch: is a pointer version of binsearch 
 * \param char* word a string, that should be checked 
 *             wheter is digit or not
 * \param struct key* tab is a apointer to structure key
 * \param int n    is a size of the tab array   
 * \return pointer to a strucure type key */
struct key * pbinsearch(char * word, struct key * tab, int n);


/* getword: get neyt word or c*/
int getword(char *, int, FILE *);

/* getchf: get a character from a file 
 * \param FILE* file is a file from the chracter has to be read
 * \return a character from the file*/
char getchf(FILE * file);

/* ungetchf: store the character in a buffer
 * \param char c the character which has to be stored */
void ungetchf(char c);

/* setstatus: sets a status of a current code part
 * \param int n is a current character came from the reading file
 * \param int* precChar is a previous character
 * \param int* token is a current status which should be changed or not */
void setstatus(int n, int *prevChar, int *token);

/* addtree: add a node with w, at or below p
 * \param struct tnode *p is the node;
 * \param char* w is he word to add in the tree 
 * \return a node of the tree*/
struct tnode *addtree(struct tnode *p, char *w);

/*treeprint: in-order print of tree p
 *
 *\param struct tnode* p is the tree */
void treeprint (struct tnode *p);

/* talloc: make a tnode 
 * \return a pointer to the structure type tnode*/
struct tnode *talloc(void);

/* strdup: make a duplicate of s
 *
 * \param char* s what has to be dublicated 
 * \return a pointer to the dublicated string*/
char *my_strdup(char *s);

/* strnend: compares n last characters of strings
 * \param char *s is a pointer to the first string
 * \param char *t is a pointer to the second string
 * \param n is the number of the last characters to be compared
 * 
 * \return 1 if the last n characters of strings are same \n
 *         0 if the last n characters diverse \n
 * */
int strnend (char *s, char *t, int n);

/* printIdentSix: prints the group of string from a tree 
 *                if the last 6 characters of the strings are same and  
 *                at least one from rest chars is distinguished
 * \param struct tnode *p is a treee where the strings are searched*/
void printIdentSix (struct tnode *p);

struct wordgroup * group_elements (struct tnode *p,  int n);
void group_treeprint (struct wordgroup *p);
#endif