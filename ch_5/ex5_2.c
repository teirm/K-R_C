#include <stdio.h>
#include <ctype.h>
#include "getch.c"

#define SIZE 10 	/* maximum size of input */

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(double *pn)
{
	int c, sign;
	double power;


	while(isspace(c = getch()))		/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);	/* not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	if (!isdigit(c)) {
		ungetch(c);
		return 0;
	}

	for (*pn = 0.0; isdigit(c); c = getch()) /* collect integer part */
		*pn = 10.0 * *pn + (c - '0');
	if (c == '.')
		c = getch();
	for (power = 1.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
		power *= 10.0;
	}
	
	*pn *= sign/power;
	if (c != EOF)
		ungetch(c);
	return c;
}

/* driver for exercise 5-1 */
int main()
{
	int n, ret, getint(double *);
	double array[SIZE];
	
	
	for (n = 0; n < SIZE && (ret = getint(&array[n])) != EOF; n++)
		if (ret != 0)
			printf("%g\n",array[n]);
}
	
