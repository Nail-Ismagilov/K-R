#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "exercise.h"

#define MAXOP    100    // max size od operator
#define NUMBER   '0'   // signal that a nuber was found

double get_stack();


void revPolish()
{
    // getarray(s, MAXOP);
    int type, op3;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != 'e') {
        
        switch (type) {
        case NUMBER:
            push (atof(s));
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
        get_stack();
    }
}


#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

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
    printf("%f, %f \n",val[0], val[1]);
}
