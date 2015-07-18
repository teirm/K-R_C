#include <stdio.h>

#define IN_COMMENT 1  	/* currently removing a comment */
#define OUT_COMMENT 0	/* currently not in a comment */ 

/* program to remove comments from a c program
    assumes comments are of BLOCK TYPE ONLY */

main()
{
	int c, state;

	state = OUT_COMMENT; 
	while ((c = getchar()) != EOF) {
		if (c ==  '/') {
			if ((c = getchar()) == '*') {
				state = IN_COMMENT;
			}
			else {
				printf("/%c",c);
			}
		}
		else if (c == '*') {
			if ((c = getchar()) == '/') {
				state = OUT_COMMENT;
			}
			else {
				printf("*%c",c);
			}
		}
		else if (state == OUT_COMMENT)
			putchar(c);
	}
}
