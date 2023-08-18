#include <chapter6.h>
#include <chapter5.h>
#define NKEYS   (sizeof (keytab)/sizeof(struct key))

/* count C keywords*/
struct key keytab[] = {
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
    
    {"unsigned", 0},
    
    {"comment", 0}

};  


int main(int argc, char *argv[])
{
    int n;
    char word[MAXWORD];
    char *file = "test.txt";

    char filePattern[] = ".txt";
    char sourceFilePattern[] = ".c";
    char headerFilePattern[] = ".h";
    
    FILE * filep;
    printf("NKEYS = %lld\n", NKEYS);
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

    while (getword(word, MAXWORD, filep) != EOF)
    {
        // if(word[0] == '#')
        //     for(int i = 0; word[i] != '\0'; i++)
        //         word[i] = word[i+1];
        if (isalpha(word[0]))
        { 
            // for(int i = 0; word[i] != '\0';i++)
            //     printf("%c",word[i]);
            // printf("\n");    

            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
        }
    }

    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n",
                    keytab[n].count, keytab[n].word);
    
    fclose(filep);
    return 0;
}
