#include <stdio.h>

#define FOLD 10 /* fold over column */
#define BROKE 1 /* currently in a piece of text */
#define FULL  0 /* out of a piece of text */


/* program to "fold over" long lines in input */

main()
{
	int c, i, state;

	i = 0;
	state = FULL;
	while ((c = getchar()) != EOF) {
		if (i == FOLD) {
			while (c != ' ' && c != '\t' && c != '\n' && c != EOF) {
				putchar(c);
				c = getchar();
			}
			putchar('\n');	
			state = BROKE;	
			i = 0;
		}
		else if (c == '\n') {
			putchar(c);	
			i = 0;
		}
		else {
			while (state == BROKE) {
				if (c  == ' ' || c == '\t') {  /* When broke has been set, the next char is already taken by the outermost while loop */
					state = BROKE;
				}
				else 
					state = FULL;
			}
			putchar(c);
			++i;
		}
	}
}
