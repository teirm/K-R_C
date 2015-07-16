#include <stdio.h>

#define MAXLINE 1000 /* maximum line length */

int get_line(char line[], int maxline);
int get_gap(char line[], int len);
void copy_clean(char to[], char from[], int len);


/* remove trailing blanks and tabs from each line of input 
   	and removes blanks lines */

main()
{
	int len;					 		/* current line length */
	char line[MAXLINE];					/* current input line */
	char temp[MAXLINE];					/* temp holder for dirty line */

	while ((len = get_line(temp, MAXLINE)) > 0) { 
		copy_clean(line,temp,len);		
		printf("%s",line);
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

/* copy_clean: copy 'from' into 'to' and remove trailing tabs/blanks; assume to is big enough */
void copy_clean(char to[], char from[], int len)
{
	int i, start_gap;

	start_gap = get_gap(from, len);

	i = 0;
	while ((to[i] = from[i]) != '\0') {
		if (from[0] == '\n') /* checks if the first character of the 'from' line is a '\n' and if it is ignores the line */
		{
			to[0] = '\0';
		}
		
		++i;
		if (i == start_gap)
		{
			to[i]='\n';
			break;
		}
	}
}

/* finds the gap beginning of the trailing characters by working backwards from the 
   	end of the line */
int get_gap(char line[], int len)
{
	int i, start_gap;

	start_gap = 0;
	for (i = len-1; i >= 0; --i) 
		if (line[i] != '\t' && line[i] != ' ' && line[i] != '\n') {
			start_gap = i+1;
			break;
		}
		
	return start_gap;
}
