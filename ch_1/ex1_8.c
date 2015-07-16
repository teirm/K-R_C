#include <stdio.h>

/* count tabs, blanks, and newlines in input */
main()
{
	int c, nt, nb, nl;
	
	nt = nb = nl = 0;
	while ((c = getchar()) != EOF) 
		if (c == '\n')
			++nl;
		else if (c == '\t')
			++nt;
		else if (c == ' ')
			++nb;
	printf("lines: %d\ttabs: %d\tblanks: %d\n", nl, nt, nb);
}
