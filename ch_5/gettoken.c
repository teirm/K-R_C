#include <string.h>
#include "get_args.c"

#define IO_ERROR -1

int check_next_token(void);

int gettoken(void) /* return next token */
{
	int c, err_ch, getch(void);
	void ungetch(int);
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(') {
		if (check_next_token() == NAME) {
			get_args();
		}
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (err_ch = *p++ = getch()) != ']'; ) {
			printf("UNMATCHED BRACKETS\n");	
			if (err_ch == ')' || err_ch == '(')
				return IO_ERROR;
		}
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		if (strcmp(token, "static") == 0 || strcmp(token, "const") == 0 || strcmp(token, "register") == 0) {
			return tokentype = QUAL;
		}
		else	
			return tokentype = NAME;
	} else
		return tokentype = c;
}

int check_next_token(void) /* checks the next token */
{
	int c;

	while ((c = getch()) == ' ' || c == '\t')
		;

	if (isalpha(c)) {
		ungetch(c);
		return tokentype = NAME;
	}
	else {
		ungetch(c);
		return c;
	}
}
		
