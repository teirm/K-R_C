#include <ctype.h>
#include <string.h>
#include "calc.h"

#define NUMBER '0' /* signal that a number was found */
#define NOPREV -99 /* make sure there was no previous */

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c, b;
	static int prev = NOPREV;

	if (prev != NOPREV && (prev != ' ' && prev != '\t')) {
		c = prev;
		prev = NOPREV;
	}
	else {
		while ((s[0] = c = getch()) == ' ' || c == '\t')
			; /* skip blank spaces */
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-' && !isalpha(c))
		return c; 	/* not a number */
	i = 0;
	if (c == '-')
		s[i] = c;
	if (isdigit(c) || c == '-') 	/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
	if (c == '.' || c == '-')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (isalpha(c))
		while (isalpha(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (strlen(s) == 1 && s[0] == '-')
		return '-';
	else if (strlen(s) == 1 && isalpha(s[0]))
		return mem_op(s);	
	else if (strlen(s) == 3)
		return trans(s);	
	else if (strlen(s) == 4)
		return mem_op(s);
	
	if (c != EOF)
		prev = c;	
	return NUMBER;
}

/* trans: catches the transcendental operations */
int trans(char s[])
{
	if (strlen(s) == 3 && s[0] == 'S' && s[1] == 'I' && s[2] == 'N')
		return 0;
	else if (strlen(s) == 3 && s[0] == 'C' && s[1] == 'O' && s[2] == 'S')
		return 1;
	else if (strlen(s) == 3 && s[0] == 'T' && s[1] == 'A' && s[2] == 'N')
		return 2;
	else if (strlen(s) == 3 && s[0] == 'E' && s[1] == 'X' && s[2] == 'P')
		return 3;
	else if (strlen(s) == 3 && s[0] == 'P' && s[1] == 'O' && s[2] == 'W')
		return 4;
	else
		return -99;
}

/* mem_op: catches the memory operations */
int mem_op(char s[])
{
	if (strlen(s) == 1)
		return 5;	
	else if (strlen(s) == 4  && s[0] == 'S' && s[1] == 'T' && s[2] == 'O' && s[3] == 'R')
		return 6;
	else if (strlen(s) == 4 && s[0] == 'L' && s[1] == 'O' && s[2] == 'A' && s[3] == 'D')
		return 7;
	else
		return -99;
}

