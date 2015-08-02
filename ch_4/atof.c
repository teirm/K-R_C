#include "atoi.c"
#include <ctype.h>

#define MAX_EXP 100 /* Maximum size of the scientific exponent */

/* atof: convert string s to double */
/* modified to account for exercise 4-2: can parse scientific notation */
double atof(char s[])
{
	double val, power;
	int i, j, k, sign, exp_sign, atoi(char []);
	int sci_exp;
	char sci_str[MAX_EXP];

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	
	val = sign * val / power;
	
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	exp_sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (j = 0; isdigit(s[i]); j++)
		sci_str[j] = s[i++];
	sci_str[j] = '\0';
	
	sci_exp = atoi(sci_str); /* converts the string representation of the exponential to a int */	

	if (exp_sign > 0) {
		for (k = 0; k < sci_exp; k++)
			val *= 10.0;
	}
	else {
		for (k = 0; k < sci_exp; k++)
			val /= 10.0;
	}
}

