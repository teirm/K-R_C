#include <stdio.h>

#define MAX_LENGTH 50	/* maximum word length */
#define MAX_FREQUENCY 10 /* maximum word frequency */
#define EMPTY 	0		/* histogram line is just zeros */
#define FILLED 	1		/* histogram line has at least one 1 */

/* creates a histogram of word counts with vertical
   	columns */
main()
{
	int i, j, c, nc, histo[MAX_LENGTH][MAX_FREQUENCY];
	int state; 

	c = nc = 0;
	for (i = 0; i < MAX_LENGTH; ++i)
		for (j = 0; j < MAX_FREQUENCY; ++j)
			histo[i][j] = 0; 

	while ((c = getchar()) != EOF) 
		if (c == ' ' || c == '\t' || c == '\n') { 
			for (j = 0; j < MAX_FREQUENCY; ++j)	
				if (histo[nc][j] != 1) {
					++histo[nc][j];
					break;
				}
			nc = 0;
		}
		else
			++nc;

	for (i = 0; i < MAX_LENGTH; ++i)
		printf("%4d", i);

	printf("\n");

	for (i = 0; i < MAX_LENGTH; ++i)
		printf("____");

	printf("\n");

	state = EMPTY;
	for (j = 0; j < MAX_FREQUENCY; ++j) {
		for (i = 0; i < MAX_LENGTH; ++i)
			
			if (histo[i][j] != 0) { 	
				printf("%4d", histo[i][j]);
				state = FILLED;
			}						
		
		if (state == FILLED) {	
			printf("\n");
			state = EMPTY;
		}
			
	}
}
