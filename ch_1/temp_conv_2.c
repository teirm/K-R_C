#include <stdio.h>

/* Print out Celsius-Farenheit table 
    celsius = 0, 20, ..., 300 */

main()
{
	float celsius, fahr;
	int lower, upper, step;

	lower = 0; 		/* lower limit of table */
	upper = 300;	/* upper limit */
	step = 20;		/* step size */

	printf("%3s\t%6s\n","C","F");

	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32.0;
		printf("%3.0f\t%6.1f\n",celsius,fahr);
		celsius += step;
	}
}
