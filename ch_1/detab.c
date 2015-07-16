#include <stdio.h>

#define TABSTOP 10 /* a tab stop occurs every TABSTOP columns */
#define DETABBED 1 /* if a tab was recently removed */
#define TABBED 0   /* there may be a tab character next */

/* replaces tabs in the input with the proper number of blank
    spaces to the next tab stop*/
main()
{
	int i, c, state;

	state = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (i = 0; i < TABSTOP; ++i) {
				putchar(' ');
			}
			
			state = DETABBED;

		}
		else if (c == ' ' && state == DETABBED) {
			; /* skip over spaces after tab removal */
		}
		else {
			putchar(c);
			state = TABBED;
		}
	}
}
