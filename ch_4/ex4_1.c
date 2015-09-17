#include <stdio.h>
#define MAXLINE 1000 /* maximum line length */

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; 	/* pattern to search for */

/* find all lines matching pattern */
int main()
{
	char line[MAXLINE];
	int found = 0;

	while (get_line(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}

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
	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;
	int right_find = 0;

	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0' && i > right_find)
			right_find = i;
	}
	
	if (right_find > 0) {
		printf("Right most location of string is: %d\n", right_find);	
		return right_find;
	}
	else
		return -1;
}
