#ifndef __CHAPTER5_H__
#define __CHAPTER5_H__

#include <stdint.h>
#include <stdio.h>

const unsigned exercise[]       =  { 0,  1,  2,  3,  4,  5,  6,  7,  8, 9, 
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

int getlines(char *s, int);

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

int getint(int *pn);
/* getint: gets int from the input 
 * \param int *pn  a pointer where the result is written
 * 
 */

char getfloat(char *pn);
/* getint: gets int from the input 
 * \param char *pn  an initial string which should be converted
 * 
 */

int strlen1(char * s);
/* strlen1: gets length of string s
 * \param char *s  an initial string 
 * \return n the length of the string s
 */

int strcmp (char * s, char * t);
/* strcmp: compares two strings
 * \param char *s  first string
 * \param char *t  second string
 * \return 0 if s=t, <0 if s<t, >0 if s>t
 */

int strend (char *s, char *t);
/* strend: checks if t at the end of s
 * \param char *s  first string
 * \param char *t  second string
 * \return 1 if t at the end of s, 0 otherweise
 */

void month_day(int, int, int *, int *);
/* month_day: set month, day from day of year
 */

int day_of_year(int year, int month, int day);
/* day_of_year: set day of year from mont & day
*/

char *alloc (int n);
/* allocation a buffer in the memory block*/

int writeLines(char *lineptr[], int nlines);
/* output having lines in the array of pointers*/

int readLine(char *lineptr[], int maxlines);
/* reading input lines */
#endif
