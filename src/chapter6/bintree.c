#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "chapter6.h"

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

/*
    add each word to a group (explicitly for the last 6 chars):
        1. add groupname (last 6 chars)
        2. make word counts
        3. if the word add to word database
    
*/

struct tnode *talloc(void)
{
    return (struct tnode*)malloc(sizeof(struct tnode));
}

struct wordgroup *galloc(void)
{
    return (struct wordgroup*)malloc(sizeof(struct wordgroup));
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
    int cond;
    int length = strlen(w);
    if (length > n)
    {
        // printf("debug: into addgroup\n");
        if (p == NULL) {        /* a new word is arrived */
            //printf("debug: p is NULL");
            p = galloc();       /* make a new node */
            p->group = my_strdup(w+(length - n));
            p->count = 1;
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
        }
        group_treeprint(p->right);
    }
}


