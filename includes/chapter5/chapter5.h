#ifndef __CHAPTER5_H__
#define __CHAPTER5_H__

#include <stdint.h>
#include <stdio.h>

const unsigned exercise[] = { 0,  1,  2,  3,  4,  5,  6,  7,  8, 9, 
                             10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                             20, 21, 22, 23, 24, 25, 26, 27, 28, 29};

unsigned int a = 3;

void strcat1(char s[], char t[]);

/* strcat: ccontantenate t to end of s; s must be big enough
 * @param s[] a character, that should be checked 
 *             wheter is digit or not
 * @param t[] a character, that should be checked
 *             wheter is digit or not
 */

int strend (char *s, char *t);

/* strcat: check if t at the end of s
 * \param s[]  an initial string
 * \param t[]  a string wich checked if it is at the en of s
 * 
 * \return  1 - if t is located at the end of s
 *          0 - if t doesnot consist in s
 */

void strcopy(char *s, char*t, int n);

/* strcat: check if t at the end of s
 * \param s[]  an initial string
 * \param t[]  a string which should be added to end of s
 * \param n    number of elements of string 't' should be added to string 's'
 * 
 */

int getlines(char *s);

/* getlines: gets given from input line and saves in array s
 * \param s[]  an initial string to save input
 * 
 * \return  length - size of array s
 */

void mygetline(char s[], int lim);
/* mygetline: gets given from input line and saves in array s
 * \param s[]  an initial string to save input
 * 
 */

long long int atoi (char *s);
/* atoi: converts given array to integer
 * \param s[]  an initial string 
 * 
 * \return n - integer value converted from array s
 */

void reverse(char s[]);
/* reverse: reverse elements of string s 
 * \param s[]  an initial string which should be converted
 * 
 */

#endif
