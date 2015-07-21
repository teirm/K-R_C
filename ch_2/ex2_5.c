#include <stdio.h>

#define FOUND 1 /* Flag to check if character is found */ 

/* A function that returns the first location of the characters from s2 in s1 
    or -1 */

main()
{
	int i;
	int j;

	int state = 0;

	char s1[] = "shark";
	char s2[] = "Cat";

	for (i = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0'; j++) {
			if (s2[j] == s1[i]) {
				printf("Character %c found in s2 at location %d\n", s1[i], j);
				state = FOUND;	
				break;
			}
		}
		if (state != FOUND) {
			printf("Character %c not in string s2\n", s1[i]);
		}
		state = 0;
	}
}
