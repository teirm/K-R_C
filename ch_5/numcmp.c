#include <stdlib.h>
#include <ctype.h>

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2, int fold, int dict)
{
	double v1, v2;
	
	if (fold == 1) {
		while (*s1!= '\0') {
			*s1 = toupper(*s1);
			s1++;
		}
		
		while (*s2 != '\0') {
			*s2 = toupper(*s2);
			s2++;
		}
	}

	v1 = atof(s1);
	v2 = atof(s2);

	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}
