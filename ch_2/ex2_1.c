#include <stdio.h>
#include <limits.h>
#include <float.h>

main()
{
	printf("Character Max: %d\n", UCHAR_MAX);
	printf("Character Min: %d\n", SCHAR_MIN);

	printf("Integer Max: %d\n", INT_MAX);
	printf("Integer Min: %d\n", INT_MIN);

	printf("Long Max: %ld\n", LONG_MAX);
	printf("Long Min: %ld\n", LONG_MIN);

	printf("Float Max: %f\n", FLT_MAX);
	printf("Float Min: %f\n", FLT_MIN);

	printf("Double Max: %lf\n", DBL_MAX);
	printf("Double Min: %lf\n", DBL_MIN);

}

