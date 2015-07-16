#include <stdio.h>

#define TABSTOP 4 /* size of a tab stop */

/* replaces blanks in text with a mixture of tabs and blanks 
   	to get an equal spacing */

main()
{
	int i, c, nb;

	nb = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		else if (c != ' ') {
			while (nb > 0) {
				if (nb >= 4) {
					putchar('\t');
					nb -= 4;
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
