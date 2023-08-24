#include <string.h>
#include "chapter5.h"

#define YES 1
#define NO  0

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

int isWordinArr(char **arr, char *word)
{
    int i, comp = 1;
    for (i = 0; *arr[i] != '\0'; i++)
    {    
        comp = strcmp(arr[i], word);
        if (!comp)
            return YES; 

    }
    return NO;
}
