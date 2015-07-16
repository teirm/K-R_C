#include <stdio.h>

#define IN 1	/* inside a word */
#define OUT 0 	/* outside a word */

/* count lines, words, and characters in input
   POSSIBLE BUGS: will not catch escape sequences
   beyond blank, newline, and tab.  Dates will
   reveal a bug (e.g. 10-AUG-15) */


main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++ nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d\t%d\t%d\n", nc, nw, nl);

}

