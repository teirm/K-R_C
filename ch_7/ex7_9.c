#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int mem_upper(char *);
	int spd_upper(char);

	char c;

	for (c = 66; c <= 90; c++)
		printf("%d %d\n", mem_upper(&c), spd_upper(c));

	return 0;
}

/* mem_upper: takes a pointer to a character and checks to see if what it points to is upper case */
int mem_upper(char *p)
{
	if (*p >= 66 && *p <= 90)
		return 1;
	else
		return 0;
}

/* spd_upper: passes by value and checks to to see if it is upper case */
int spd_upper(char q)
{
	if (q >= 66 && q <= 90)
		return 1;
	else
		return 0;
}
