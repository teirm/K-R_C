#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

#define FIELD_LEN 100

/* minprintf: minimal printf with varaible argument list */
void minprintf(char *fmt, ...)
{
	va_list ap; 	/* points to each unnamed arg in turn */
	char *p, *sval, width[FIELD_LEN], *w;
	int ival, w_flag, field;
	double dval;

	w = width;

	va_start(ap, fmt); /* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++) {
		
		if (*p != '%') {
			putchar(*p);
			continue;
		}

		if ((isdigit(*++p))) {
			while (isdigit(*p)) 
				*w++ = *p++;

			*w = '\0';
			field = atoi(width);
			--p;
			w_flag = 1;
		}
		else 
			--p;


		switch (*++p) {
			case 'd':
				ival = va_arg(ap, int);
				if (w_flag == 1)
					printf("%*.d", field, ival);
				else
					printf("%d", ival);
				w_flag = 0;
				break;
			case 'f':
				dval = va_arg(ap, double);
				if (w_flag == 1)
					printf("%*f", field, dval);
				else
					printf("%f", dval);
				w_flag = 0;
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
					putchar(*sval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap); /* clean up when done */
}

int main(int argc, char *argv[])
{
	minprintf("Here is an int %30d\n", 10);
	minprintf("Here is a double %30f\n", 10.0000);
	minprintf("Here is a string %s\n", "Good bye");

	return 0;
}
