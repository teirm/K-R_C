#include <stdio.h>

/* rotates bits n bits right */

main()
{
	int x = 8;
	int n;

	n = 3;
	while (n > 0) {
		if ((x & 1) == 1) {
			x = (x >> 1) | ~(~0U >> 1); /* the 0U is key since you will not do sign extension, only 0 extention */
		}
		else {
			x = (x >> 1);
		}

		n--;
	}
}
