#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

/* reverse: reverse string s in place */
void reverse (char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* itoa: covert n to characters in s */
/* Origianl program on page 64 of K&R does not handle largest negative in
    twos-complement system because the positive equivalent does not exist.
	e.g. -128 to 127 since zero must be accounted for */
void itoa (int n, char s[])
{
	int i, sign;
	unsigned int m;

	if ((sign = n) < 0) /* record sign */
		m = -n;
	else
		m = n;
	i = 0;
	do {		/* generate digits in reverse order */
		s[i++] = m % 10 + '0'; /* get next digit */
	} while ((m /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main()
{
	int n = 134;
	char s[MAX_LENGTH];

	itoa(n,s);

	printf("%d is now %s\n",n,s);

	return 0;
}
