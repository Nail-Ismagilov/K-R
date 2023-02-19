#include <stdio.h>
#include "chapter5.h"

#define MAX_LENGTH 50
#define SIZE       20

void printString (char strin[])
{
    while(*strin != '\n')
    {
        printf("%c", *strin);
        strin++;
    }
}



int main()
{
    printf("\n\n********************************* CHAPTER 5 *********************************\n\n");
   // printf("********************************* Exercise %d *********************************\n\n", exercise[a]);

    // char str1[MAX_LENGTH] = "first string";
    // char str2[] = "_second string";

    // printf("is str2 at the end of str1? (1-YES; 0-NO): %d\n", strend(str1, str2));
    // strcopy(str1, str2, 20);


    // printf("str1[]: ");
    // for(int i = 0; str1[i] != '\0'; i++)
    // {
    //     printf("%c", str1[i]);
    // }
    //     printf("\nis str2 at the end of str1? (1-YES; 0-NO): %d\n", strend(str1, str2));

    // int n, array;

    // n = 10;
    // char flNumber[n];
    // getint(&array);
    // printf("%d", array);

    // getfloat(&flNumber);
    // printString(flNumber);

    /*####### EXERCISE 5-3, 5-4, 5-5, 5-6 #######*/

    char s[MAX_LENGTH] = "I love";
    char t[MAX_LENGTH] = " You";
    
    char c1[MAX_LENGTH] = "I love You";
    char c2[MAX_LENGTH] = " You";

    strcat1(s, t);

    for (int i=0; s[i] != '\0'; i++)
         printf("%c", s[i]);

    printf("\n");
    if (strend(s, t))
        printf("T is not at the end of s\n");
    else
        printf("T  at the end of s\n");

    if (strend(c1, c2))
        printf("c2 at the end of c1");
    else
        printf("c2 is not at the end of 1");

    return 0;
}