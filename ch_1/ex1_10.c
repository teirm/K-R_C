#include <stdio.h>

/* replaces tabs with "\t", backspace with "\b", and \ with "\\" in input */

main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t')
			printf("%s", "\\t");	
		else if (c == '\b')
			printf("%s", "\\b");	
		else if (c == '\\')
			printf("%s%s", "\\", "\\");	
		else
			putchar(c);
	}
}
