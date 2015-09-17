#include "getch.c"

/* getword: get next word or character from input */
int getword(char *word, int lim, int *line_no)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;

	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
		if (!isalnum(*w = getch()) && *w != '#' && *w != '"' && *w != '_' && *w != '/' && *w != '*') {
			if (*w == '\n')
				(*line_no)++;
			ungetch(*w);
			break;
		}

	*w = '\0';
	return word[0];
}
