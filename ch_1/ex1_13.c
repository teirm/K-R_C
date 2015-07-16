#include <stdio.h>

#define MAX_LENGTH  50 	/* maximum length of a word in input */

/* histogram of word lengths in input */
main()
{
	int i, j, c, nc, histogram[MAX_LENGTH];

	nc = c = 0;
	for (i = 0; i < MAX_LENGTH; ++i)
		histogram[i] = 0;

	while((c = getchar()) != EOF)
		if (c == ' ' || c == '\t' || c == '\n') {
			++histogram[nc];
			nc = 0;
		}
		else
			++nc;

	for (i = 0; i < MAX_LENGTH; ++i) {
		printf("%2d| ", i); 
		if (histogram[i] != 0)
			for (j = 0; j < histogram[i]/500.0; ++j)
				printf("*");
		printf("\n");
	}
}

