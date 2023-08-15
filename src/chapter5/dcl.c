#include "string.h"
#include "stdio.h"
#include "ctype.h"

#define MAXTOKEN    100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;                      /* type of last token */
char token[MAXTOKEN];               /* last token string */
char name[MAXTOKEN];                /* identifier name */
char datatype[MAXTOKEN];            /* data type = int, char, etc. */
char out[1000];                     /* output striung */


FILE * file; 


 

int main()  /* convert declarations to words */
{
    file = fopen("declaration.txt","r"); 
    while (gettoken() != EOF)   /* 1st token on line */
    {
        strcpy(datatype, token);    /* is the datatype */
        out[0] = '\0';
        dcl();          /* parse rest of line */
        if (tokentype != '\n')
        {
            printf("syntax error\n");
        }
        printf("%s: %s %s\n", name, out, datatype);
    }
    fclose(file);
    return 0;
}

/* dcl: parse a declaration*/
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*'; )    /* count *'s */
        ns++;
    dirdcl();
    while(ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl: parse a direct declaration*/
void dirdcl(void)
{
    int type;

    if (tokentype == '(')   /* ( dcl )*/
    {
        dcl();
        if (tokentype != ')')
        {
            printf("error: missing )\n");
        }
            
    } 
    else if (tokentype == NAME)     /* variable name */
    {
        strcpy(name, token);
    }
    else
        printf("error: expected name or (dcl)\n");


    while ((type=gettoken()) == PARENS || type == BRACKETS)
    {
        switch (type)
        {
            case PARENS:     
                        strcat(out, " function returning");
                        break;
            case BRACKETS:
                        strcat(out, " array");
                        strcat(out, token);
                        strcat(out, " of");
                        break;
            // case FUNARG:
            //             strcat(out, " function passing ");
            //             strcat(out, token);
            //             strcat(out, " and returning");
            //             break;
            default:
                        break;
        }
    }    
}

/* return next token */
int gettoken(void)
{
    
    int c;
    char *p = token;

    while ((c = fgetc(file)) == ' ' || c == '\t')   /* skipping blanks and tabs*/
        ;

    if (c == '(')                                   /* if the character is a open paran*/
    {
        if ((c = fgetc(file)) == ')')               /* check if the next character is a closing paran*/
        {   
            strcpy(token, "()");
            tokentype = PARENS;
        }
        else
        {
            ungetc(c, file);
            tokentype = '(';
        }

    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = fgetc(file)) != ']';)
            ;
        *p = '\0';
        tokentype = BRACKETS;

    } 
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = fgetc(file));)
            *p++ = c;
        *p = '\0';
        ungetc(c, file);
        tokentype = NAME;
    }

    else 
    {
        tokentype = c;
    }
    return tokentype;
}



