#include <string.h>
#include "chapter5.h"
// int strlen1(char * s)
// {
//     char *p = s;
//     while (*p++)
//         ;
//     return p-s;
// }

int strnend (char *s, char *t, int n)
{
    int retVal       = 0;
    int lengthT, lengthS;
    /*counting digits in string T*/
    lengthT = strlen1(t);
    
    /*Counting digits in string s*/
    lengthS = strlen1(s);

    /*check if the first string longer as the string which should be included in*/
    if ((lengthS < n) && (lengthT < n))
     {
        retVal = 0;
     }   
    
    if (!(strcmp( s +(lengthS - n), t +(lengthT - n))))
        {   
            retVal = 1;
        }

    // printf("debug: strend compare. retVal == %d", retVal);
    return retVal;
}