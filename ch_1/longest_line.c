#include <stdio.h>
#define MAXLINE 100 		/* maximum input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
	int c, len;					 		/* current line length */
	int max;							/* maximum length seen so far */
	char line[MAXLINE];					/* current input line */
	char longest[MAXLINE];				/* longest line saved here */

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len == (MAXLINE-1) && line[MAXLINE-2] != '\n') {
			while ((c = getchar()) != '\n' && c != EOF)
				++len;
			++len; 	/* to account for the newline at the end of the line */	
			printf("Line is too long.  Truncating to %d characters\n", MAXLINE);	
		}
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)	/* there was a line */
		printf("%s\nlength: %3d\n", longest, max);
	return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
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
