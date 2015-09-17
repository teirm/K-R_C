#include <stdio.h>
#include <stdlib.h> 	/* for atof() */
<<<<<<< HEAD
#include <math.h>
#include "stack_op.c"
#include "get_op.c"
#include "calc_mem.c"
#include "calc.h"

#define MAXOP 		100 	/* max size of operand oor operator */

#define NUMBER		'0'		/* signal that a number was found */
#define SINE_OP 	0		/* signal for SINE */
#define COSINE_OP 	1		/* signal for COSINE */
#define TANGENT 	2		/* signal for TANGENT */
#define EXPTL		3		/* signal for EXPONENTIAL */	
#define POWER		4		/* signal for POWER */

#define VARIABLE	5		/* signal for a VARIABLE */
#define STORE_OP	6		/* signal to STORE current val in VARIABLE */
#define LOAD_OP		7		/* signal to LOAD val from VARIALBLE */
=======
#include "stack_op.c"
#include "get_op.c"
#include "calc_mem.c"


#define MAXOP 100 		/* max size of operand oor operator */
#define NUMBER '0'		/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
>>>>>>> 16622dc5f8b557529594827122d43c61edeaea87

/* reverse Polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];

<<<<<<< HEAD
	init_mem();

=======
>>>>>>> 16622dc5f8b557529594827122d43c61edeaea87
	while ((type = getop(s)) != EOF) {
			switch (type) {
			case NUMBER: 
				push(atof(s));
				break;
<<<<<<< HEAD
			case SINE_OP:
				push(sin(pop()));
				break;
			case COSINE_OP:
				push(cos(pop()));
				break;
			case TANGENT:
				push(tan(pop()));
				break;
			case EXPTL:
				push(exp(pop()));
				break;
			case POWER:
				op2 = pop();
				push(pow(pop(),op2));
				break;
			case VARIABLE:
				push(toupper(s[0]));
				break;
			case STORE_OP:
				store((int)pop(),pop());
				break;
			case LOAD_OP:
				push(load((int)pop()));
				break;
=======
>>>>>>> 16622dc5f8b557529594827122d43c61edeaea87
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() /op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
<<<<<<< HEAD
				printf("\t%.8g\n",peek());
				print_store(pop());
=======
				printf("\t%.8g\n",pop());
>>>>>>> 16622dc5f8b557529594827122d43c61edeaea87
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

