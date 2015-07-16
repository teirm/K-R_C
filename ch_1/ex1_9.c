#include <stdio.h>

/* copy input to output replacing a string of one 
   	or more blanks with a single blank */

#define IN 1 	/* in a string of blanks */
#define OUT 0	/* outside a string of blanks */

main()
{
	int c, state;	
	
	state = OUT;

	while ((c = getchar()) != EOF) {
		if (c == ' ' && state == OUT) {
			putchar(' ');
			state = IN;
		}
		else if (c != ' ') {
			putchar(c);
			state = OUT;
		}
	}
}
