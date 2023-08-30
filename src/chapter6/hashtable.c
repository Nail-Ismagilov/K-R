#include    <stdio.h>
#include    <stdint.h>
#include    <stdlib.h>
#include    "chapter6.h"




/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;

    for(hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup; looks for s in hashtab */
struct nlist * lookup(char *s)
{
    struct nlist *np;

    for(np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;      /* found */
    return NULL;            /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    uint8_t hashval;

    if ((np = lookup(name)) == NULL)    /* not found */
    {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
    {
        free ((void *) np->defn); /* free previous defn */
    }
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

/* ubdef: remoce definition and name*/
uint8_t undef(char *name, char *defn)
{
    //printf("debug_undef: into undef\n");
    struct nlist *np;
    struct nlist *p;

    uint8_t hashval;
    uint8_t retVal = 0;
    hashval = hash(name);

    //printf("debug_undef: hashval = %d\n", hashval);

    if ((np = lookup(name)) == NULL)
        return retVal;

    if (strcmp(hashtab[hashval]->name, name) == 0)
    {
        p = hashtab[hashval];
        hashtab[hashval] = hashtab[hashval]->next;
        free((void *)p);
        retVal = 1;
        //printf("debug_undef: retVal = %d\n", retVal);
    }

    if(hashtab[hashval] != NULL)
    {
        for(np = hashtab[hashval]->next; np->next != NULL; np = np->next)
        {
            //printf("debug_undef: retVal2 = %d\n", retVal);
            {
                if(strcmp(name, np->next->name) == 0)
                {
                    p = np->next;
                    np->next = np->next->next;
                    free((void *)p);
                    retVal = 1;
                }
            }
        }
    }
    
    //printf("debug_undef: retVal = %d\n", retVal);
    return retVal;
}
    