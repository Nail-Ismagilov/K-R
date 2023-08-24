#include <chapter6.h>
#include <chapter5.h>

#define NKEYS   (sizeof (keytab)/sizeof(struct key))

/* count C keywords*/
struct key keytab[] = {
    {"/*", 0},
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"define", 0},
    {"do", 0},
    {"double", 0},
    {"else", 0},
    {"enum", 0},
    {"extern", 0},
    {"float", 0},
    {"for", 0},
    {"goto", 0},
    {"if", 0},
    {"include", 0},
    {"int", 0},
    {"long", 0},
    {"register", 0},
    {"return", 0},
    {"signed", 0},
    {"static", 0},
    {"sizeof", 0},
    {"short", 0},
    {"struct", 0},
    {"switch", 0},
    {"typedef", 0},
    {"union", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"unsigned", 0}
};  



   char *vars[] = {"char","double", "float", "int","long", "short","void"};  


int main(int argc, char *argv[])
{
    int n;
    char word[MAXWORD];

    // struct key *p;
    char *file = "test.txt";
    int token = KEYWORD;                /* Current status */
    int prevChar = '\0';               /* previous character */
    int lineNumber = 1;

    char filePattern[] = ".txt";
    char sourceFilePattern[] = ".c";
    char headerFilePattern[] = ".h";
    
    struct tnode *root;
    struct wordgroup *wordroot;
    struct lnode *line;

    root = NULL;
    wordroot = NULL;
    line = NULL;


    FILE * filep;
    // printf("NKEYS = %lld\n", NKEYS);
    while (--argc > 0 )
    {
        if ((strend(*argv, filePattern))       || 
            (strend(*argv, sourceFilePattern)) || 
            (strend(*argv, headerFilePattern))  )
        {    
            file = *argv;
        }    
    
    }
    
    filep = fopen(file, "r");

    while ((n = getword(word, MAXWORD, filep)) != EOF)
    {

        if (n == '\n')
        {
            lineNumber++;
        }
            
        if ((isalpha(word[0])) && (KEYWORD == token || NOT_DEFINED == token))
        { 
                //printf("debug: isalpha true\n\tword: %s\n", word);
                // wordCopy = my_strdup(word);
                root = addtree(root, word); 
                line = addtreeline(line, word, lineNumber);
        }
        else
        { 
            
            setstatus(n, &prevChar, &token);
            // printf("prevChar: %c CurrentChar: %c token %d\n", prevChar, n, token);
            if (KEYWORD == token)
                prevChar = '\0';
            else
                prevChar = n;
        }
    
    }
    
    // treeprint(root);

    wordroot = group_elements(root, 4); /* grouping elements */
    // group_treeprint(wordroot);          /* print the groups and their elements*/
    
    printf(" count \t\tWORD\t\t\t\tLINE\n");
    for(int i = 0; i<100; i++)
        printf("-");
    printf("\n");

    printWordLines(line);

    fclose(filep);
    return 0;
}
