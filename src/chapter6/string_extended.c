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

int isWordinArr(char **arr, char *word, int length)
{
    // printf("debug: I am in the word array checking\n");
    int i, comp;

    for (i = 0; i < length; i++)
    {   
        // printf("debug: *arr[%d] - %s\tword - %s\n", i, arr[i], word);
        comp = strcmp(arr[i], word);
        // printf("debug: comp == %d\n", comp);
        if (comp == 0)
        {   
            return YES; 
        }
    }
    // printf("debug: I am off from the word array checking\n");
    return NO;
}
