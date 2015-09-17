#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getch.c"

#define MAXTOKEN 100
#define IO_ERROR -1 /* An error in the user input */

enum { NAME, QUAL, PARENS, BRACKETS };

int dcl(void);
int dirdcl(void);

int gettoken(void);
int tokentype;				/* type of last token */
char token[MAXTOKEN];		/* last token string */
char name[MAXTOKEN];		/* identifier name */
char qualifiers[MAXTOKEN];	/* qualifiers = const, static, register */
char arguments[MAXTOKEN];	/* argument types */
char datatype[MAXTOKEN];	/* data type = char, int, etc */
char out[1000];				/* output string */


#include "dcl.c"
#include "gettoken.c"


int main()
{
	int return_check;
	int line_no = 1;


	while (gettoken() != EOF) { 	/* 1st token on line */
	
		qualifiers[0] = '\0';
		arguments[0] = '\0';

		while (tokentype == QUAL) {
			strcat(qualifiers, token);
			strcat(qualifiers, " ");	
			gettoken();
		}
			
		strcpy(datatype, token);	/* is the datatype */
		out[0] = '\0';
		return_check = dcl();	/* parse rest of line */

		if (tokentype != '\n' || return_check == IO_ERROR) {
			printf("syntax error on line %d\n", line_no);
			continue;
		}
		printf("%s: %s%s %s\nRequired Arguments: %s\n", name, qualifiers, out, datatype, (arguments[0] == '\0') ? "None" : arguments);

		line_no++;	
	
	}
	return 0;
}
