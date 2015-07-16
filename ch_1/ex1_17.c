#include <stdio.h>
#define MAXLINE 1000 		/* maximum input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
	int len;					 		/* current line length */
	char line[MAXLINE];					/* current input line */

	while ((len = get_line(line, MAXLINE)) > 0) 
		if (len > 40)	/* there was a line */
			printf("%slength: %3d\n", line, len);
	return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = '\n';
		++i;
	} 
	s[i] = '\0';


	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
