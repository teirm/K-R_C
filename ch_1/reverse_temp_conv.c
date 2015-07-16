#include <stdio.h>

#define LOWER 0		/* lower limit of table */
#define UPPER 300   /* upper limit */
#define STEP 20		/* step size */


/* print Farenheit - Celsius table in reverse */

main()
{
	int fahr;

	for(fahr = UPPER; fahr >= LOWER ; fahr -= STEP) {
		printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr - 32));
	}
}
