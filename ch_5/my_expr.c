#include <stdio.h>
#include <ctype.h>

#include "stack_op.c"
#include "atof.c"


double atof(char *s);
void push(double f);
double pop(void);

int main(int argc, char *argv[])
{
	int c;
	int op2;
	
	if (argc > 1) {
		while (--argc > 0) {
			switch((*++argv)[0]) {
				case '+':
					push(pop() + pop());
					break;
				case '-':
					op2 = pop();
					push(pop() - op2);
					break;
				case '*':
					push(pop() * pop());
					break;
				case '/':
					op2 = pop();
					if (op2 == 0) {
						printf("ERROR: ZERO DIVISOR\n");
						break;
					}
					push(pop() / op2);
					break;
				case '\n':
					printf("%g\n",pop());
					break;
				default:
					push(atof(*argv));
					break;
			}
		}
	}
	printf("%g\n",pop());
	return 0;
}
