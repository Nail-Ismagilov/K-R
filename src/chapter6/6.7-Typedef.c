/*
 * The file contains examples and exercises from K&R 
 * "The C Proggramming languages" book. Chapter 6.7
 * "Typedef" and concerned for license free using.
 */

/* C provides a facility called typedef for creating new data type names.
 *      typedef int Length
 * makes the name Length a synonym for int. The type Length can be used in declaration, casts, etc*/
#include <string.h>
#define MAXLINES    500
typedef Length;

Length len, maxlen;
Length *lengths[];

/* Similarly the declarations*/

typedef char *String;

/* makes String a synonym to char * or character pointer */
String p, lineptr[MAXLINES], alloc(int);
int strcmp(String, String);
String salloc(String)
{
    p = (String) malloc(100);
    return p;
}

typedef struct tnode *t_treeptr;

typedef struct tnode{
    char *word;
    int count;
    t_treeptr left;
    t_treeptr right;
} t_treenode;


/* This creates two new type keywords callrf Treenode (a structure) 
 * and t_treeptr (a pointer tto the structure). Then the routnie 
 * talloc coulf become: */

t_treeptr talloc(void)
{
    return (t_treeptr)malloc(sizeof(t_treenode));
}

