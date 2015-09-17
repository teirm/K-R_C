#include <stdio.h>
#include "atoi.c"

#define TABSTOP 4  /* size of a tab stop */
#define ARG_LEN 10 /* length of single argument */
#define ERROR -1   /* ERROR in input */

int atoi(char *s);

/* note: dereferencing NULL results in segfault */

/* replaces blanks in text with a mixture of tabs and blanks 
   	to get an equal spacing */
int main(int argc, char *argv[])
{
	int i, c, nb, nc;
	int col_start = 0;
	int col_every = 0;

	char *arg_str; 

	while (--argc > 0 && ((c = (*++argv)[0]) == '-' || c == '+'))
		switch(c) {
			case '+': /* col_start */
				arg_str = ++argv[0];
				col_start = atoi(arg_str);			
				printf("%d\n", col_start);	
				break;
			case '-': /* every n columns */
				arg_str = ++argv[0];
				col_every = atoi(arg_str);
				printf("%d\n", col_every);
				break;
			default:
				printf("entab: illegal option %c\n", c);
				argc = ERROR;
				break;
		}

	if (argc != 0)
		printf("Usage: entab -m +n < \"input\"\n");
	else 
		while ((c = getchar()) != EOF) {
			++nc;
			if (nc >= col_start) {
				if (c == ' ')
					++nb;
				else if (c != ' ') {
					while (nb > 0) {
						if (nb >= col_every) {
							putchar('\t');
							nb -= col_every;
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
}
