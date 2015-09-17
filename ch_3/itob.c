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

/* itob: covert n to characters in base b in s */
void itob (int n, char s[], int b)
{
	int i, sign;
	int remainder;	
	unsigned int m;

	if ((sign = n) < 0) /* record sign */
		m = -n;
	else
		m = n;
	i = 0;
	do {		/* generate digits in reverse order */
		remainder = m % b;	/* get next digit */

		if (remainder > 9) {
			remainder -= 10;
			s[i++] = remainder + 'A';
		}
		else
			s[i++] = remainder + '0';
	} while ((m /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main()
{
	int n = 23134;
	int b = 16;

	char s[MAX_LENGTH];


	itob(n,s,b);

	printf("%d is %s in base %d\n",n,s,b);

	return 0;
}
