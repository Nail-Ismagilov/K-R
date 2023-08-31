#include "chapter6.h"

void exercise6_2_6_3(void)
 {  

    printf("\n\n ~~~~~~~~~~ EXERCISE 6.2-6.3 ~~~~~~~~~~\n");
    int n;
    char word[MAXWORD];
    char space[BUFF];

    // struct key *p;
    int status = CODE;                 /* Current status */
    int prevChar = '\0';               /* previous character */
    int lineNumber = 1;

    struct tnode *root;
    struct wordgroup *wordroot;
    struct lnode *line;

    root = NULL;
    wordroot = NULL;
    line = NULL;

    
    char *file = "Text_files\\code.txt";                /* file containing code */
    FILE * filep;

    filep = fopen(file, "r");


    while ((n = getword(word, MAXWORD, filep, space)) != EOF)
    {

        if (n == '\n')
        {
            lineNumber++;
        }

        if ((isalpha(word[0])) && (CODE == status || NOT_DEFINED == status))
        { 
                //printf("debug: isalpha true\n\tword: %s\n", word);
                // wordCopy = my_strdup(word);
                root = addtree(root, word); 
                line = addtreeline(line, word, lineNumber);
        }
        else
        { 
            
            setstatus(n, &prevChar, &status);
            // printf("prevChar: %c CurrentChar: %c status %d\n", prevChar, n, status);
            if (CODE == status)
                prevChar = '\0';
            else
                prevChar = n;
        }
    
    }
    fclose(filep);
    // treeprint(root);

    // wordroot = group_elements(root, 4); /* grouping elements */
    // group_treeprint(wordroot);          /* print the groups and their elements*/

    printf(" count \t\tWORD\t\t\t\tLINE\n");
    for(int i = 0; i<100; i++)
        printf("-");
    printf("\n");

    printWordLines(line);

    printf("\n\n ~~~~~~~~~~ EXERCISE 6.2-6.3 ~~~~~~~~~~\n");
 }
