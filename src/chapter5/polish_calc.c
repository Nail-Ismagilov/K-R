#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "chapter5.h"

#define MAXOP    100    // max size od operator
#define NUMBER   '0'   // signal that a number was found
#define MAXVAL   100

int sp = 0;
double val[MAXVAL];

double get_stack();


void revPolish(int argc, char *arr[])
{
    // getarray(s, MAXOP);
    int type, op3, app = 0, i = 0;
    double op2;
    char s[MAXOP];

    // while (*++arr != '\0'){
    //     app++;
    //     printf("%c, ", *arr);
    // }
    
    // // for (i = 0; arr[i] != '\0'; i++)
    //     printf("%f, ", atof(arr-=app));

    for (i = 1; i < argc; ++i)  {
        
        switch (arr[i][0]) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            push (atof(arr[i]));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0){
                push(pop() / op2);
            }
            else {
                printf("error: zero divisor\n");
            }
            break;
        case '%':
            op3 = pop();
            push((int)pop() % op3);
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown error\n");
            break;
        }
        
    }
    get_stack();
}




void push (double f){
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
 
double pop(void){
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
    {
        return c;      // not a number
    }
    i = 0;
    if (isdigit(c)) // collect integer part
    {
        while(isdigit(s[++i] = c = getch()))
            ;
        //printf("\nnumber %c\n",s[i-1]);
    }
    if (c == '.')   // collect fractional part
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (!isdigit(c))
    {
        ungetch(c);
    }
    return NUMBER;
}

double get_stack(){
    printf("%f \n",val[0]);
}
