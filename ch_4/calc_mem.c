#include <stdio.h>
#include <ctype.h>

#define MEM_MAX 25

/* memory for the chapter 4 calculator program: only provides 26 variables A - Z */

double memory[MEM_MAX];

/* init_mem: sets all memory slots to 0.0 */
void init_men(void)
{
	int i;

	for (i = 0; i < MEM_MAX; i++)
		memory[i] = 0.0;
}

/* store: puts value in variable */
void store(char c, double val)
{
	memory[toupper(c) - 65] = val;
}

/* load: load the value from variable */
double load(char c)
{
	return memory[toupper(c) - 65];
}
