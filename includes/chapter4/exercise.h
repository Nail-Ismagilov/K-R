#ifndef __EXERCISE_H__
#define __EXERCISE_H__

#include <stdint.h>
#include <stdio.h>

void getarray(char s[], int len);

/* getarray: stores input to an array and prints it
 *
 * @param char s[] - array where the input should be tored 
 * @param int len - size of the array  
 **/



void print_array(char arr[]);

/* print_array: prints array to a terminal
 *
 * @param arr - an array which should be printed
 * */


uint8_t strrindex(char s[], char t[]);

/* strrindex: returns position of righmost occurence t in s 
 *
 * @param s main string 
 * @param t string that will be searched in s
 */

double atof(char s[]);

/* atof: converts string to double
 *
 * @param s the string, that should be converted to double
 */

#endif
