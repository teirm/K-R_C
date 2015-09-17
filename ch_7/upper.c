#include <stdio.h>
#include <ctype.h>
#include <string.h>

void upper(void);
void lower(void);

int main(int argc, char *argv[])
{
	if (strcmp(argv[0], "./upper") == 0)
		upper();
	else if (strcmp(argv[0], "./lower") == 0)
		lower();
	else
		printf("Error: Incorrect input\n");

	return 0;
}

void upper(void)
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(toupper(c));

}

void lower(void)
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(tolower(c));

}
