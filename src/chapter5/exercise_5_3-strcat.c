#include <stdio.h>
#include <string.h>

int strlen1(char * s)
{
    char *p = s;
    while (*p++)
        ;
    return p-s;
}

void strcat1(char *s, char *t)
{
    while (*s++)
        ;
    s--;
    while ((*s++ = *t++))
        ;
}

void strcopy(char *s, char*t, int n)
{
    
    while (*s++)
        ;
    s--;
    while(n-- != 0)
    {
       *s++ = *t++;
    }
}

int strcmp_f (char * s, char * t)
{
   
    for (; (*s >= 'A' && *s <= 'Z') ? *s + 0x20 : *s == (*t >= 'A' && *t <= 'Z') ? *t + 0x20 : *t ; s++, t++)
        if (*s == '\0')
            return 0;
    
    return (*s - *t);
}

int strend (char *s, char *t)
{
    int retVal       = 0;
    int lengthT, lengthS;
    /*counting digits in string T*/
    lengthT = strlen1(t);
    
    /*Counting digits in string s*/
    lengthS = strlen1(s);

    /*check if the first string longer as the string which should be included in*/
    if (lengthS < lengthT)
     {
        retVal = 0;
     }   

    if (!(strcmp( s +(lengthS - lengthT), t)))
        {   
            retVal = 1;
        }
       

    return retVal;
}
