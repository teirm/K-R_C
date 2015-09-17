#include <string.h>
#include <stdio.h>

#define MAX_LEN 100


/* itoa_rec: covert n to characters in s */
void itoa(int n, char s[])
{
	int i;
	int sign;

	i = 0;

	if (n < 0) { 
		s[i++] =  '-';
		s[i] = '\0';
		n = -n;
	}
	if (n / 10) {
		itoa(n/10,s);
	}
	s[strlen(s)] = n % 10 + '0';

	s[strlen(s)] = '\0';
}

int main()
{
	int n = -127;
	char s[MAX_LEN];

	itoa(n,s);
	printf("%s\n", s);
}
