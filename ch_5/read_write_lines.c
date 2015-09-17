#define MAXLEN 1000			/* max length of a string */

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; /* delete new line */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int reverse)
{
	int i;

	if (reverse == 1) {
		for (i=nlines-1; i>=0; --i)
			printf("%s\n", lineptr[i]);
	}
	else {
		for (i=0; i<nlines; i++)
			printf("%s\n", lineptr[i]);
	}
}
