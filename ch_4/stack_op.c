#include "getch.c"

#define MAXVAL 100 /* maximum dept of val stack */

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("ERROR: STACK FULL, CAN'T PUSH %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* peak: returns the value at top of stack, stack unchanged */
double peak(void)
{
	if (sp > 0)
		return val[sp - 1];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* duplicate: replicates the top value of the stack */
void duplicate(void)
{
	if (sp > 0)
		push(peak());
	else {
		printf("error: stack empty\n");
	}
}

/* swap: swaps the top two elements of the stack */
void swap(void)
{
	double temp;

	if (sp > 0) {
		temp = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = temp;
	}
	else {
		printf("error: stack empty\n");
	}
}	

/* clear: clears the stack */
void clear(void)
{
	if (sp > 0)
		sp = 0;
	else
		printf("error: stack empty\n");
}
