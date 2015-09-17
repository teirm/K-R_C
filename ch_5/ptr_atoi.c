#include <stdio.h>

/* ptr_atoi: convert s to integer using pointers */
int atoi(char *s)
{
	int  n = 0;

	while(*s >= '0' && *s <= '9')
		n = 10 * n + (*s++ - '0');
	return n;
}

/* Driver for ptr_atoi code */
/* int main()
{
	char s[] = "1231";
	printf("%d\n",atoi(s));
}*/

