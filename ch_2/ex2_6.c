#include <stdio.h>

/* program that returns x with the n bits that begin at 
    p set to right most n bits of y, leaving others unchanged */

main()
{
	int x;
	int y;
	int p;
	int n;
	int temp;

	x = 8;
	y = 12;

	p = 4;
	n = 3;

	temp = y;

	y = (y & ~(~0 << n)) << (p+1-n);

	printf("y: %d\n",y);
	
	temp = ((temp | (~0 << n)) << (p+1-n)) | ~(~0 << n);

	printf("temp: %d\n", temp);

	x = (x | y) & (temp);

	printf("%d\n", x);

}
