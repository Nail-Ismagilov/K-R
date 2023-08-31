#include "chapter6.h"


void exercise6_5()
{
    printf("\n\n ~~~~~~~~~~ EXERCISE 6.5 ~~~~~~~~~~\n");
    
    struct nlist *np;
    char *name = "IN";
    char *defn = "100";

    
    np = install("IN", defn);
    if (np != NULL)
        printf("name: %s \ndefn: %s\n", np->name, np->defn);
    else
        printf("error: np couldnot be initialized\n");

    np = install("NI", "two hundred");
    undef(name, defn);

    np = lookup("NI");
    if (np != NULL)
        printf("name: %s \ndefn: %s\n", np->name, np->defn);
    else
        printf("error: np couldnot be initialized\n");
    printf(" ~~~~~~~~~~ EXERCISE 6.5 ~~~~~~~~~~\n\n");
}
