#include "string.h"
#include "stdio.h"
#include "ctype.h"

#define MAXTOKEN    100

enum {NAME, PARENS, BRACKETS, FUNARG};
enum {OK, ERROR};

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;                      /* type of last token */
char token[MAXTOKEN];               /* last token string */
char temptoken[MAXTOKEN];           /* temporar token*/
char name[MAXTOKEN];                /* identifier name */
char datatype[MAXTOKEN];            /* data type = int, char, etc. */
char out[1000];                     /* output striung */
int error_status = OK;


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
            error_status = ERROR;
            printf("syntax error\n");
        }
        if (!error_status)
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
            error_status = ERROR;
            printf("error: missing )\n");
        }
    } 
    else if (tokentype == NAME)     /* variable name */
    {
        strcpy(name, token);
    }
    else
    {
        error_status = ERROR;
        printf("error: expected name or (dcl)\n");
    }

    while ((type=gettoken()) == PARENS || type == BRACKETS || type == FUNARG)
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
            case FUNARG:
                        strcat(out, " function passing ");
                        strcat(out, token);
                        strcat(out, " and returning");
                        break;
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
    char *temp = temptoken;
    while ((c = fgetc(file)) == ' ' || c == '\t')                       /* skipping blanks and tabs*/
        ;

    if (c == '(')                                                       /* if the character is a open paran*/
    {
        if ((c = fgetc(file)) == ')')                                   /* check if the next character is a closing paran*/
        {   
            strcpy(token, "()");
            tokentype = PARENS;
        }
        else if (isalpha(c))                                             /* check if the function has arguments */
        {
            
            *p = '\0';  /* clear token array*/
            
            for (*temp++ = c; (*temp++ = fgetc(file)) != ')';)
                {
                    if (*(temp-1) == ' ' || *(temp) == '\t')             /* skipping blanks and tabs*/
                        temp--;
                    if (*(temp-1) == '*')                                /* searching for a pointer sign */
                    {   
                        *(temp-1) = '\0';
                        if (temptoken[0] == ',')                        /* taking the comma to the beginning of the string*/
                        {
                            
                            strcat(token, ", ");
                            for(int i; temptoken[i] != '\0'; i++)
                                temptoken[i] = temptoken[i+1];
                        }
                        strcat(token, "pointer to ");
                        strcat(token, temptoken);
                        temp = &temptoken[0];
                    }
                    
                }
            *(temp-1) = '\0';
            strcat(token, temptoken);
            tokentype = FUNARG;
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
        {

            if (!(isdigit(*(p-1)) && *(p-1) != '[' && *(p-1) != ']'))
            {
                if (!error_status)
                {
                    printf("error: index should be a number or non-sized\n");
                }
                error_status = ERROR;
            }
        }
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



