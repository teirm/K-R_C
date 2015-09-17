#include <stdio.h>
#include <ctype.h>

#define MEM_MAX 25

/* memory for the chapter 4 calculator program: only provides 26 variables A - Z */

double memory[MEM_MAX];

/* init_mem: sets all memory slots to 0.0 */
<<<<<<< HEAD
void init_mem(void)
=======
void init_men(void)
>>>>>>> 16622dc5f8b557529594827122d43c61edeaea87
{
	int i;

	for (i = 0; i < MEM_MAX; i++)
		memory[i] = 0.0;
}

/* store: puts value in variable */
void store(char c, double val)
{
<<<<<<< HEAD
	memory[c - 65] = val;
=======
	memory[toupper(c) - 65] = val;
>>>>>>> 16622dc5f8b557529594827122d43c61edeaea87
}

/* load: load the value from variable */
double load(char c)
{
<<<<<<< HEAD
	return memory[c - 65];
}

void print_store(double val)
{
	store('Z', val);
	printf("Value %lf stored in variable \'Z\'\n", val);
=======
	return memory[toupper(c) - 65];
>>>>>>> 16622dc5f8b557529594827122d43c61edeaea87
}
