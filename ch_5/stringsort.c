#include <stdio.h>
#include <string.h>
#include "alloc.c"
#include "my_qsort.c"

#define MAXLINES 5000 	/* max #lines to be sorted */
#define TOTALLEN 10000 /* total len */
#define MAXLEN 1000	/* max length of any input lines */

char *lineptr[MAXLINES];	/* pointers to text lines */

int readlines(char *lineptr[], int nlines, char lines[]);
void writelines(char *lineptr[], int nlines);

void my_qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
	char lines[TOTALLEN];

	int nlines;		/* number of input lines read */
	if ((nlines = readlines(lineptr, MAXLINES, lines)) >= 0) {
		my_qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

int get_line(char *, int);
char *alloc(int);

/* get_line: read a line into s, return length */
int get_line(char *s, int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
		*s++ = c;
	if (c == '\n')
		*s++ = c;

	*s = '\0';
	return i;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char l[])
{
	int len, nlines, line_pos;
	char *p, line[MAXLEN];

	line_pos;
	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = &l[line_pos]) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; /* delete new line */
			strcpy(p, line);
			lineptr[nlines++] = p;
			line_pos += len;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i=0; i<nlines; i++)
		printf("%s\n", lineptr[i]);
}
