#include <stdio.h>
#include <ctype.h>
#include "getch.c"

#define SIZE 10 /* maximum size of input */

int getch(void);
void ungetch(int);

/* getint: get next integer form input into *pn */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch())) 	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	if (!isdigit(c)) {
		ungetch(c);
		return 0;
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

/* driver for exercise 5-1 */
int main()
{
	int n, array[SIZE], getint(int *);
	int ret;
	
	for (n = 0; n < SIZE && (ret = getint(&array[n])) != EOF; n++)
		if (ret != 0)
			printf("%d\n",array[n]);

}
	
