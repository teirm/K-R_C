#include <stdio.h>

#define swap(t,x,y) { t temp;\
	temp = x;\
	x = y;\
	y = temp; }

int main()
{
	int x = 7;
	int y = 8;

	printf("x = %d\ny = %d", x, y);

	swap(int,x,y);

	printf("x = %d\ny = %d\n", x, y);

	printf("%s\n",SYSTEM);

	return 0;
}	 
