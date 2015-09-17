#include <stdio.h>
#include <stdlib.h> 	/* for atof() */
#include <ctype.h>		/* for isdigit() */
#include "get_line.c"
#include "stack_op.c"

#define MAXOP	1000	/* max size of operand or operator */
#define NUMBER '0'		/* signal that a number was found */
#define ENDIO 1		/* signal that output is over */ 

int lp;
char calc_line[MAXOP];

void push(double); double pop(void);
int get_line(char[], int);
int find_op(char[]);

/* reverse Polish calculator */
int main()
{
	int type, length;
	double op2;
	char s[MAXOP];
	
	while((get_line(calc_line, MAXOP)) > ENDIO) { /*ENDIO is used since an empty line is still parsed as len 1 by get_line*/
			lp = 0;			
			while (lp != strlen(calc_line)) {
				type = find_op(s);
			switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				printf("%g\n",peek());	
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				break;
			
			}	
		}	
	}	
	return 0;
}

int find_op(char s[])
{
	int i = 0;	
	int c = 0;

	while ((c = calc_line[lp++]) != '\0' && c != ' ' && c != '\t') {
		if(isdigit(c) || c == '.')
			s[i++] = c;
		else { 
			return c;
		}
	}
	s[i] = '\0';
	return NUMBER;

}
