#include <stdio.h>

#define TABSTOP 4 /* size of a tab stop */

/* replaces blanks in text with a mixture of tabs and blanks 
   	to get an equal spacing */

int main(int argc, char *argv[])
{
	int i, c, nb;
	int tab_count = 0;

	if (argc > 1) {
		while (--argc > 0)
			if ((*++argv)[0] = '\\' && (*argv)[1] == 't')
				tab_count++;
	}
	else
		tab_count = TABSTOP;

	nb = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		else if (c != ' ') {
			while (nb > 0) {
				if (nb >= tab_count) {
					putchar('\t');
					nb -= tab_count;
				}
				else
				{
					putchar(' ');
					--nb;
				}
			}
			putchar(c);
		}
	}
}
