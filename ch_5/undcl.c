#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getch.c"

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

int gettoken(void);
int tokentype;				/* type of last token */
char token[MAXTOKEN];		/* last token string */
char name[MAXTOKEN];		/* identifier name */
char datatype[MAXTOKEN];	/* data type = char, int, etc */
char out[1000];				/* output string */

#include "gettoken.c"



/* undcl: convert word description to declaration */
int main()
{
	int type;
	char temp[MAXTOKEN];

	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n') {
			printf("%c\n",type);
			if (type == PARENS || type == BRACKETS)
				strcat(out, token);
			else if (type == '*') {
				if (check_next_token() == NAME) {
					sprintf(temp, "*%s", out);
				}
				else {
					sprintf(temp, "(*%s)", out);
				}
				strcpy(out, temp);
			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else
				printf("invalid input at %s\n", token);
		}
		printf("%s\n", out);
	}
	return 0;
}
