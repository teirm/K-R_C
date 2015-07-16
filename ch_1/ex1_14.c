#include <stdio.h>

#define MAX_LENGTH  128 	/* number of characters in ASCII table */

/* histogram of word lengths in input */
main()
{
	int i, j, c, histogram[MAX_LENGTH];

	c = 0;
	for (i = 0; i < MAX_LENGTH; ++i)
		histogram[i] = 0;

	while((c = getchar()) != EOF)
			++histogram[c];

	for (i = 0; i < MAX_LENGTH; ++i) {
		if (i < 32)
			printf("%3d   |", i);
		else
			printf("%3d %2c|", i, i);
		if (histogram[i] != 0)
			for (j = 0; j < histogram[i]/1200.0; ++j)
				printf("*");
		printf("\n");
	}
}

