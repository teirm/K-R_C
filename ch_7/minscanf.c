#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

/* minscanf: minimal scanf with variable argument list */
int minscanf(char *fmt, ...)
{
	va_list ap;		/* points to each unnamed arg in turn */
	char *p, *sval;
	int c, *ival, check;
	double dval;

	va_start(ap, fmt);

	c = getchar();
	for (p = fmt; *p; p++) {
	
		if (*p == '%') {
			switch(*++p) {
				case 'd':
					ival = va_arg(ap, int *);
					scanf("%d", ival);	
					break;
			}
			continue;
		}
		

		if (isspace(*p))
			continue;

		while (isspace(c))
			c = getchar();




		if (c != *p)
			return 0;
		
		c = getchar();




	}
	va_end(ap);
}

int main(int argc, char *argv[])
{

	int d, e;

	minscanf("This is an int: %d %d\n", &d, &e);

	printf("%d %d", d, e);

	return 0;
}
