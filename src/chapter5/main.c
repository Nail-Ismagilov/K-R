#include <stdio.h>
#include "chapter5.h"

#define MAX_LENGTH 50

int main()
{
    printf("\n\n********************************* CHAPTER 5 *********************************\n\n");
   // printf("********************************* Exercise %d *********************************\n\n", exercise[a]);

    char str1[MAX_LENGTH] = "first string";
    char str2[] = "_second string";

    printf("is str2 at the end of str1? (1-YES; 0-NO): %d\n", strend(str1, str2));
    strcopy(str1, str2, 20);


    printf("str1[]: ");
    for(int i = 0; str1[i] != '\0'; i++)
    {
        printf("%c", str1[i]);
    }
        printf("\nis str2 at the end of str1? (1-YES; 0-NO): %d\n", strend(str1, str2));

    return 0;
}