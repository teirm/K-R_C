#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1000 	/* max length of string */

/* ptr_reverse: reverses a string in place */
void ptr_reverse(char *s)
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = *(s+i);
		*(s+i) = *(s+j);
		*(s+j) = c;
	}
}

/* ptr_itoa: convert n to characters in s
    will not work with the largest negative 
	in a two's complement system */
void ptr_itoa(int n, char *s)
{
	int sign;
	
	if ((sign = n) < 0)
		n = -n;
	do {
		*s++ = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		*s++ = '-';
	*s = '\0';


}

/* driver for ptr_itoa */
/* some strange scope issues here */
int main()
{
	int d = 12313;
	char s[MAXLENGTH];
	
	ptr_itoa(d,s);

	ptr_reverse(s);

	printf("%s\n", s);

	return 0;
}
