#include <stdio.h>
#include <ctype.h>

#include "getword.c"
#include "stack_op.c"

#define MAX_LEN 100 	/* maximum length of a string */

void perform_op(char);

int main(int argc, char *argv[])
{
	int getword(char *, int);	
	char op, token[MAX_LEN];	
	double val;
	double pop(void);	
	void push(double);


	while (getword(token, MAX_LEN) != EOF) {
		if (sscanf(token, "%lf", &val) == 1)
			push(val);	
		else if (sscanf(token, "%c", &op) == 1)
			perform_op(op);
		else
			printf("Invalid Input\n");
	}

	printf("%lf\n", pop());

	return 0;
}

void perform_op(char c)
{
	double op2;	
	switch (c) {
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
				printf("Divide by Zero Error\n");
				break;
			} else 
				push(pop() / op2);
			break;
		case '\n':
			printf("lf\n", pop());
			break;
		default:
			printf("Unsupported op %c\n", c);
			break;
	}
}
