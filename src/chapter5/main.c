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
    int a = 0;

    strcat1(s, t);

    for (int i=0; s[i] != '\0'; i++)
         printf("%c", s[i]);


    return 0;
}