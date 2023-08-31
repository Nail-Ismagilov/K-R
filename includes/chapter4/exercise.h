#ifndef __EXERCISE_H__
#define __EXERCISE_H__

#include <stdint.h>
#include <stdio.h>

double atof(char s[]);
/* atof: convert array of characters to float number
 *
 * @param char s[] - array where the character of a number stored 
 **/

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

// double atof(char s[]);     // used stdlib.h instead
/* atof: converts string to double
 *
 * @param s the string, that should be converted to double
 */


void push (double f);
/* push: push f onto value stack
 *
 * @param f double valuse that pushed to stack
 *
 */

double pop(void);
/* pop: pop and return top value from stack
 *
 */

int getop(char s[]);
/* getop: get next operator or numeric operand
 *
 *
 * 
 */

int getch(void);
/* getch: get a (possibly pushed back) character
 * 
 */

void ungetch(int);
/* ungetch: push character back on input
 *
 */

void revPolish();
/* revPolish: a polish calculator
 *
 *
 */

void reverse(char *s);
/* reverse: reversing a string
*
*   @char *s: is a string (arrax of chars), which needs to be reversed
*/
#endif
