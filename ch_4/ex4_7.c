#include <stdio.h>
#include "getch.c"

#define MAXLEN 1000	/*defines the max length of a string */

int getch(void);
int ungets(char s[]);

int main()
{
	int i, c;
	char s[MAXLEN];

	while ((c = getch()) != EOF)
		s[i++] = c;
	s[i] = '\0';
	ungets(s);
	while (i-- > 0)
		printf("%c\n", getch());
}
