#include <stdio.h>

#define MAXSIZE 1000	/* maximum size of an input*/


/* ptr_getline: getline function that uses points in stead of arrays */
int ptr_getline(char *s, int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
		*s++ = c;
	if (c == '\n')
		*s++ = c;

	*s = '\0';
	return i;
}

/* driver for ptr_getline 
int main()
{
	char s[MAXSIZE];

	ptr_getline(s, MAXSIZE);

	printf("%s\n", s);

	return 0;
} */
	

