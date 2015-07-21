#include <stdio.h>

/* modified squeeze program that will delete any character 
    in string s1 found in string s2 */

main()
{
	int i, j, k;
	char s1[] = "Fish sticks";
	char s2[] = "Yak Sauce";

	for (i = 0; s2[i] != '\0'; i++) {
		for (j = k = 0; s1[j] != '\0'; j++) {
			if (s1[j] != s2[i]) {
				s1[k++] = s1[j];
			}
		}
		s1[k] = '\0';
	}

	printf("Squeezed string is: %s\n", s1);
}
