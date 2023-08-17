#include <chapter6.h>
#include <chapter5.h>
#define NKEYS   (sizeof keytab/sizeof(struct key))

/* count C keywords*/
struct key keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char, 0"},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"do", 0},
    {"double", 0},
    {"else", 0},
    {"enum", 0},
    {"extern", 0},
    {"for", 0},
    {"goto", 0},
    {"if", 0},
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

int main(int argc, char *argv[])
{
    int n;
    char word[MAXWORD];
    char **lineptr;
    char *file = "test.txt";
    char filePattern[] = ".txt";
    char sourceFilePattern[] = ".c";
    char headerFilePattern[] = ".h";
    int count = 0;
    int nlines;
    int i = 0;
    
    while (--argc > 0 )
    {
        if ((strend(*argv, filePattern))       || 
            (strend(*argv, sourceFilePattern)) || 
            (strend(*argv, headerFilePattern))  )
        {    
            file = *argv;
        }    
    }
    printf("Function start...\n");

    nlines = read_file(lineptr, file);

    // for (int i = 0;i < nlines; i++)
    {
        while (getword(word, MAXWORD, lineptr[i++] != EOF)
        {
            printf("Enter while loop... loop count: %d\n", count++);
            if (isalpha(word[0]))
                if((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
            break;
        }
    }
    for (n = 0; n < NKEYS; n++)
    {
        if (keytab[n].count > 0)
            printf("%4d %s\n", 
                    keytab[n].count, keytab[n].word);
    }

    return 0;
}