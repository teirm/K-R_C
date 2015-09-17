#include <stdio.h>
#include <ctype.h>

#define LINE_LEN 175  /* soft-cap on number of characters in a line */

int main(int argc, char *argv[])
{
	int c;
	int char_counter=0;


	while ((c = getchar()) != EOF) {
		
		if (c >= 32 && c != 127)
			putchar(c);
		else
			printf("%o", c);
		char_counter++;

		if (char_counter == LINE_LEN) {
			c = getchar();
			
			while (!isspace(c)) {
				if (c >= 32 && c != 127)
					putchar(c);
				else
					printf("%o", c);
				c = getchar();
			
				if (c == EOF)
					return 0;
			
			}
			putchar('\n');
			char_counter = 0;
		}
	}

	return 0;
}
