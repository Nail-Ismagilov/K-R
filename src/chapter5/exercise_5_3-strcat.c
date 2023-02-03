#include <stdio.h>

void strcat1(char *s, char *t)
{
    while (*s++)
        ;
    s--;

    while(*t != '\0')
    {
       *s = *t;
        s++;
        t++;
    }
}

void strcopy(char *s, char*t, int n)
{
   int numberOfChar = n;
    
    while (*s++)
        ;
    s--;

    while(n != 0)
    {
       *s = *t;
        s++; t++; n--;
    }
}

int strend (char *s, char *t)
{
    int ret       = 1;
    int lengthS   = 0;
    int lengthT   = 0;

    /*counting digits in string T*/
    while (*t++)
        lengthT++;
    
    /*Counting digits in string s*/
    while (*s++)
        lengthS++;

    /*check if the first string longer as the string which should be included in*/
    if (lengthS < lengthT)
     {
        ret = 0;
        return ret;
     }   
        
    s -= lengthT;
    t -= lengthT;

    while (*s != '\0')
    {
        /*check if the elemnt of 's' same as the element of 't*/
        if (*s++ != *t++)
        {
            ret = 0;
            break;
        }
    } 

    return ret;
}