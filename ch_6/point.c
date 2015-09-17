#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	struct point {
		int x;
		int y;
	};

	struct point maxpt = { 320, 200 };
	double dist, sqrt(double);

	printf("%d,%d\n", maxpt.x, maxpt.y);

	dist = sqrt((double)maxpt.x * maxpt.x + (double)maxpt.y * maxpt.y);

	printf("Distance from origin of maxpt is: %g\n", dist);

	return 0;
}
