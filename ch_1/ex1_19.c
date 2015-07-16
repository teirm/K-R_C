#include <stdio.h>
#define MAXLINE 1000 		/* maximum input line size */

int get_line(char line[], int maxline);
void reverse(char to[], char from[], int len);

/* will reverse input, line by line */
main()
{
	int len;					 		/* current line length */
	char line[MAXLINE];					/* current input line */
	char temp[MAXLINE];					/* a temporary holder */

	while ((len = get_line(temp, MAXLINE)) > 0) {
			reverse(line, temp, len);					
			printf("%s\n", line);
	}
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
void reverse(char to[], char from[], int len)
{
	int i;
	
	for (i = 0; i<len; ++i)
	{
		to[i] = from[len-1-i];
	}
	to[len] = '\0';	
	
}

