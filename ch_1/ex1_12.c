#include <stdio.h>

//#define IN 	1	/* inside a word */
//#define out 0	/* outside a word */

/* prints input one word per line */
main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') 
			printf("\n");
		else if (c != '\n')
			putchar(c);
	}
}
