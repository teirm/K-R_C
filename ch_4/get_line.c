#include <stdio.h>

/* get_line: get line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = '\n';
	s[i] = '\0';
<<<<<<< HEAD
	
=======
>>>>>>> 16622dc5f8b557529594827122d43c61edeaea87
	return i;
}
