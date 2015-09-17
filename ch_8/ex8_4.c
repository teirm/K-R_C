#include <stdio.h>
#include "syscalls.h"

int main(int argc, char *argv[])
{
	FILE *fp;

	fp = fopen("input_1.txt", "r");

	printf("%d\n", fp->fd);

	fclose(fp);

	return 0;
}
