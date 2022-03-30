/* Exercise 2-4. Write an alternative version of "squeeze(s1, s2)" that deletes
 *  * each character in "s1" that matches any character in the string "s2". */

#include <stdlib.h>
#include <stdio.h>

#define MAXLEN	40	/* maximum size of the strings */
#define YES	 1
#define NO	 0

void mygetline(char s[], int lim);
void squeeze(char s1[], char s2[]);

int main() {

		int c, i, lim;
			char s1[MAXLEN + 1], s2[MAXLEN + 1];

				lim = MAXLEN;

					printf("Enter s1: ");
						mygetline(s1, lim);

							printf("Enter s2: ");
								mygetline(s2, lim);

									squeeze(s1, s2);

										printf("Resulting string is \"%s\"\n", s1);
											
											exit(0);
}

void mygetline(char s[], int lim) {

		int c, i;

			for (i = 0; i < lim && (c = getchar()) != '\n' && c != EOF; ++i)
						s[i] = c;

				s[i] = '\0';
}

void squeeze(char s1[], char s2[]) {

		int i, j, n, found;

			for (i = j = 0; s1[i] != '\0'; ++i) {
						found = NO;
								for (n = 0; s2[n] != '\0'; ++n)
												if (s1[i] == s2[n])
																	found = YES;
										if (!found)
														s1[j++] = s1[i];
											}

				s1[j] = '\0';
}
