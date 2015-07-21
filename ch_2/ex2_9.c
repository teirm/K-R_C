#include <stdio.h>

/* a faster method of bitcount that takes advantage of the ripple 
    carry effect in a twos-complement number system */

int fast_bitcount(unsigned x)
{
	int b = 0;

	while (x > 0) {
		x &= (x-1);	
		b++;
	}

	return b;
}

int main()
{
	int x = 20;

	printf("%d has %d 1 bits\n", x, fast_bitcount(x));

	return(0);
}

