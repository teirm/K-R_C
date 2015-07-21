#include <stdio.h>

/* Function to flip a set of bits starting at p and going to n */

main()
{
	int x = 8;
	int copy = 0;	
	int p = 4;
	int n = 3;

	int mask_center; /* makes 0001-1100 */
	int inverter;

	mask_center = (~(~0<<n))<<(p+1-n);	
	
	//mask_edges = (~0 << (p+1)) | ~(~0 << (p+1-n)); /* only use ~mask */

	printf("mask edges: %d\n",mask_center);

	copy = x;

	x &= mask_center;

	x ^= ~0;

	x &= copy | mask_center;

	printf("%d\n",x);

}
