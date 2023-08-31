
#ifndef __CHAPTER6_H__
#define __CHAPTER6_H__

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

#define MAXWORD  100
#define HASHSIZE    101
#define BUFF    200

// char SPACE_BUFF[BUFF];
static struct nlist *hashtab[HASHSIZE];     /* pointer table */

struct key{ 
    char *word;
    int count;
} ;  

typedef struct tnode *t_treeptr;
struct tnode{               /* the tree node: */
    char *word;             /* points to the text */
    int count;              /* number of occurences */
    t_treeptr left;         /* left child */
    t_treeptr right;        /* right child */
};

typedef struct line *t_ltreeptr;
struct line{
    int n;
    t_ltreeptr left;
    t_ltreeptr right;
};

typedef struct lnode *t_lntreeptr;
struct lnode{               /* the tree node: */
    char *word;             /* points to the text */
    int count;              /* number of occurences */
    t_ltreeptr line;        /* lines where the word occurs*/
    t_lntreeptr left;       /* left child */
    t_lntreeptr right;      /* right child */
};

typedef struct wordgroup *t_wtreeptr;

struct wordgroup{           /* group of words with same last 6 chars*/
    char *group;            /* points to the name of the group */
    t_treeptr word;         /* points to the words database */
    int count;              /* counts number of words in the group*/
    t_wtreeptr left;        /* left child */
    t_wtreeptr right;       /* right child */
};


struct nlist {       /*table entry: */
    struct nlist *next;     /* next entry in chain */
    char *name;             /* definend name */       
    char *defn;             /* replacement text */
};

enum { CODE                  = 0, 
       STRING                = 1, 
       COMMENT               = 2, 
       MULTIPLE_LINE_COMMENT = 3, 
       DEFINE                = 4,
       NOT_DEFINED           = 5, 
       END_ML_COMMENT        = 6 };

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
int getword(char *, int, FILE *, char * space);

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
 * \param int* status is a current status which should be changed or not */
void setstatus(int n, int const *prevChar, int *status);

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

/* galloc: make a wordgroup 
 * \return a pointer to the structure type wordgroup*/
struct wordgroup *galloc(void);


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

/* group_elements: groups words with the same n endings
 * \param struct tnode *p is a bintree which storess words to be grouped
 * \param int n the last n charater patterns of word to group
 * 
 * \retutrn pointer to root value of bintree of grouped elements
 */
struct wordgroup * group_elements (struct tnode *p,  int n);

/* group_treeprint: prints elements of bintree
 * \param struct wordgroup *p is a bintree to print 
*/
void group_treeprint (struct wordgroup *p);



/* addtreeline: adds to a tree of data adding line number
 * \param struct lnode *p is the node;
 * \param char* w is he word to add in the tree 
 * \return a node of the tree*/
struct lnode *addtreeline(struct lnode *p, char *w, int line);

/* tlalloc: make a lnode 
 * \return a pointer to the structure type wordgroup*/
struct lnode *tlalloc(void);

/* addline: adds line number nline in a tree on the right or the left side 
 * \param struct line *lines is the node;
 * \param int nline the number to add in the tree
 * \return a node of the tree */
struct line * addline(struct line *lines, int nline);

/* lalloc: make a line 
 * \return a pointer to the structure type wordgroup*/
struct line *lalloc(void);

/* printWordLines: prints elemencts of bintree
 * \param struct lnode *lineNode is a bintree to print 
*/
void printWordLines(struct lnode *lineNode);

/* printLineNumber: prints elements of bintree
 * \param struct line * line is a bintree to print 
*/
void printLineNumber(struct line * line);

/* isWordinArr: check if the given word in the given array of words
 * \param char **arr is array of words
 * \param char *word is a word to check
 * \param int length is the length of the array of words
 * \return 1 if the word in the array, otherweise 0*/
int isWordinArr(char **arr, char *word, int length);


/* hash: form hash value for string s 
 * \param char* s is an input string to be hashed
 * \return unsigned hash number*/
unsigned hash(char *s);

/* lookup: looks for s in hashtab 
 * \param char *s string of the target name
 * \return pointer to struct nlist where the name *s is stored */
struct nlist * lookup(char *s);

/* install: put (name, defn) in hashtab 
 * \param char* name the name to be added
 * \param char* defn is the definition to be added
 * \return a new head of the linked list*/
struct nlist *install(char *name, char *defn);

/* ubdef: remove definition and name
 * \param char* name the name to be added
 * \param char* defn is the definition to be added
 * \return 1 if the node is deleted, 0 otherweise*/
uint8_t undef(char *name, char *defn);

/* exerise6_1: 
 *  getword which handle underscores, string constants,
 *  comments, or preprocessor control lines*/
void exerise6_1(void);

/* exercise6_5: 
 *  there is a function undef, that removes 
 *  a name and definittion from the table maintained by
 *  lookup and install */    
void exercise6_5(void);

/* exercise6_6: 
 *  Simple version of the 'define processor */
void exercise6_6(void);

/* exercise6_2_6_3: 
 *  6.2 - reads C programm and prints in alphabetic order 
 *  each group of variablenames that are identical in the 
 *  last 6 chars.
 *  6.3 - cross-referencer that prints a list of all words 
 *  in a document, and for each word , a list of the line 
 *  numbeers on wich it occurs*/
void exercise6_2_6_3(void);

#endif