#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "chapter6.h"

static char *NOISY_WORDS[] = {"the", "in", "at", "to",  /* array of noisy words to avoid in the listing */
              "that", "or", "on", "of", "an", "a"};

int arrLength = 10; /* size of the NOISY_WORDS array */

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    // printf("debug: into addtree\n");
    if (p == NULL) {        /* a new word is arrived */
        //printf("debug: p is NULL");
        p = talloc();       /* make a new node */
        p->word = my_strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->count++;         /* repeated word */
    }
    else if (cond < 0)      /* less than into left subtree */
    {
        p->left = addtree(p->left, w);
    }
    else                    /* greater than into right subtree*/
    {
        p->right = addtree(p->right, w);
    }
    //printf("debug: end of addtree\n");
    return p;
}


void treeprint (struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}


struct tnode *talloc(void)
{
    return (struct tnode*)malloc(sizeof(struct tnode));
}

struct wordgroup *galloc(void)
{
    return (struct wordgroup*)malloc(sizeof(struct wordgroup));
}

struct line *lalloc(void)
{
    return (struct line*)malloc(sizeof(struct line));
}

struct lnode *tlalloc(void)
{
    return (struct lnode*)malloc(sizeof(struct lnode));
}

char *my_strdup(char *s)   /* make a duplicate of s */
{
    char *p;

    p = (char *) malloc(strlen(s) + 1);     /* +1 for '\0'*/
    if(p != NULL)
        strcpy(p, s);
    return p;
}


struct wordgroup *addgroup(struct wordgroup *p, char *w, int n)
{
    int length = strlen(w);
    if (length > n)
    {
        int cond;
        // printf("debug: into addgroup\n");
        if (p == NULL) {        /* a new word is arrived */
            //printf("debug: p is NULL");
            p = galloc();       /* make a new node */
            p->group = my_strdup(w+(length - n));
            p->count = 1;
            p->word = NULL;
            p->word = addtree(p->word, w);
            p->left = p->right = NULL;
        }
        else if ((cond = strcmp(w+(length - n), p->group)) == 0)
        {
            // printf("debug: addgroup string %s\n", w);
            p->count++;         /* repeated word */
            p->word = addtree(p->word, w);/*add word*/
        }
        else if (cond < 0)      /* less than into left subtree */
        {
            // printf("debug: addgroup string > 1 %s\n", w);
            p->left = addgroup(p->left, w, n);
        }
        else                    /* greater than into right subtree*/
        {
            // printf("debug: addgroup string < 1 %s\n", w);
            p->right = addgroup(p->right, w, n);
        }
    }
    //printf("debug: end of addtree\n");
    return p;
}

struct wordgroup * group_elements (struct tnode *node, int n)
{
    struct tnode *temp;
    static struct wordgroup *group;
    if (node == NULL)
        return NULL;
    // printf("debug: into group elements \n");

    group_elements(node->right, n);

    temp = node->right;
    if (temp != NULL)
    {    
        // printf("debug: add group: %s \n", temp->word);
        group = addgroup(group, temp->word, n);
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
    }

    temp = node->left;
    if (temp != NULL)
    {
        // printf("debug: add group: %s \n", temp->word);
        group = addgroup(group, temp->word, n); 
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
    }

    group_elements(node->left, n);
    return group;
}

void group_treeprint (struct wordgroup *p)
{
    // printf("debug: print grouptree\n");
    if (p != NULL)
    {
        group_treeprint(p->left);
        if ((p->count) > 1)
        {
            printf("=====================\n");
            printf(" -- Group: %s --\n", p->group);
            printf("=====================\n");
            treeprint (p->word);
            printf("\n");
        }
        group_treeprint(p->right);
    }
    
}

struct line *addline(struct line *lines, int nline)
{

  //   printf("debug: I am in the addline\n");
    if (lines == NULL)      /* a new line os arrived */
    {
      //   printf("debug: adding line\n");
        lines = lalloc();   /* make a new node */ 
        lines->n = nline; 
        lines->left = lines->right = NULL;  
    }
    else if (((lines->n) > nline)? 1 : 0)      /* less than into left subtree */
    {
        lines->left = addline(lines->left, nline);
      //   printf("debug: addtreeline into left\n");
    }
    else                    /* greater than into right subtree*/
    {
        lines->right = addline(lines->right, nline);
      //   printf("debug: addtreeline into right\n");
    }

  //   printf("debug: finish adding the line\n");
    return lines;
}

struct lnode *addtreeline(struct lnode *p, char *w, int line)
{
    
  //   printf("debug: I am in the add tree\n");
    // printf("debug: into addtree\n");
    if (isWordinArr(NOISY_WORDS, w, arrLength) == 0)
    {   
        int cond;
        if (p == NULL) {        /* a new word is arrived */

        //   printf("debug: create line tree - p is NULL\n");
            p = tlalloc();       /* make a new node */
            p->word = my_strdup(w);
            p->count = 1;
            p->line = NULL;
            p->line = addline(p->line, line);
            // printf("added line number %d\n", p->line->n);
            p->left = p->right = NULL;
        //   printf("debug: line added, node created\n");
        }
        else if ((cond = strcmp(w, p->word)) == 0)
        {
        //   printf("debug: addtreeline repeated line\n");
            p->count++;         /* repeated word */
            p->line = addline(p->line, line);
            // printf("added line number %d\n", p->line->n);     
        }
        else if (cond < 0)      /* less than into left subtree */
        {
            p->left = addtreeline(p->left, w, line);
        //   printf("debug: addtreeline into left\n");
        }
        else                    /* greater than into right subtree*/
        {
            p->right = addtreeline(p->right, w, line);
        //   printf("debug: addtreeline into right\n");
        }
    }
    //printf("debug: end of addtree\n");
    return p;
}


void printWordLines(struct lnode *lineNode)
{
    if (lineNode != NULL)
    {
        printWordLines(lineNode->left);
        printf("%4d %20s\t", lineNode->count, lineNode->word);
            printLineNumber(lineNode->line);
        printf("\n");
        printWordLines(lineNode->right);
    }
}

void printLineNumber(struct line * line)
{
    
    if (line != NULL)
    { 
        printLineNumber(line->left);
        printf(" %3d ", line->n); 
        printLineNumber(line->right); 
    }
}

