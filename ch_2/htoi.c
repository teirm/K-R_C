#include <stdio.h>

/* program to convert a hex string to 
    decimal equivalent */

main ()
{
	int i;
	long n;
	char s[] = "0XFFFFA23FFF";

	n = 0;
	for (i = 2; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'); ++i) {
		
		if (s[i] >= '0' && s[i] <= '9') {
			n = 16 * n + (s[i] - '0');
		}
		else if (s[i] >= 'a' && s[i] <= 'f') {
			n = 16 * n + (s[i] - 87);
		}
		else 
			n = 16 * n + (s[i] - 55);
	}
	printf("The value of HEX %s in DEC is: %ld\n", s, n);
}
