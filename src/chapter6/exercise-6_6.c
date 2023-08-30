#include "chapter6.h"


void exercise6_6()
{
    printf("\n\n ~~~~~~~~~~ EXERCISE 6.5 ~~~~~~~~~~\n");


    /* file location */
    char *prepfile = "Text_files\\preprocessor.txt";    /* output from preprocessor */
    char *file = "Text_files\\code.txt";                /* file containing code */
    
    int n;
    char space[BUFF];
    char word[MAXWORD];
    char *name[MAXWORD];
    char *defn[MAXWORD];
    struct nlist *np;
    char *wordCopy;

    /* file pointer */
    FILE * prepfilep;
    FILE * filep;

    // struct key *p;
    int status = CODE;                 /* Current status */
    int prevChar = '\0';               /* previous character */
    np = NULL;


    prepfilep = fopen(prepfile, "w");
    filep = fopen(file, "r");

    while ((n = getword(word, MAXWORD, filep, space)) != EOF)
    {
        setstatus(n, &prevChar, &status);

        if (DEFINE == status && isalpha(word[0]))
        {
            strcpy(name, word);
        }
        else if (DEFINE == status && isdigit(word[0]))
        {
            strcpy(defn, word);
            install(name, defn);
        }

        if ( (CODE == status) || STRING == status )
        {
            wordCopy = my_strdup(word);
            if (((np = lookup(wordCopy)) != NULL) && CODE == status)
            {
                strcpy(wordCopy, np->defn);
            }    
            
            fprintf(prepfilep, "%s%s", space, wordCopy);
        }
        else
        { 
            if (CODE == status)
                prevChar = '\0';
            else
                prevChar = n;
            // printf("debug: prevChar = %c\n", prevChar);
        }
    }

    // CLOSING OPEN FILES
    fclose(prepfilep);
    fclose(filep);
    printf("status: success - ouptut in %s\n", prepfile);
    printf(" ~~~~~~~~~~ EXERCISE 6.5 ~~~~~~~~~~\n\n");
}