#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 120 /* maximum length of a line */

/* ex7_6: compares two files and prints the line where first difference occus */
int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	int line_no;	
	char line_1[MAX_LEN];
	char line_2[MAX_LEN];

	if (argc != 3) /* two files for comparison not provided */
		printf("Usage: ./ex7_6 file1 file2\n");
	else {
		if ((fp1 = fopen(*++argv, "r")) == NULL) {
			fprintf(stderr, "Can't open file1\n");
			exit(1);
		}
		if ((fp2 = fopen(*++argv, "r")) == NULL) {
			fprintf(stderr, "Can't open file2\n");
			exit(1);
		}

		while (fgets(line_1, MAX_LEN, fp1) != NULL && fgets(line_2, MAX_LEN, fp2) != NULL) {
			line_no++;	
			if (strcmp(line_1, line_2) != 0) {
				printf("FILES DIFFER ON LINE NUMBER %d:\n\t%s\n\t%s\n", line_no, line_1, line_2);
				exit(0);
			}
		}

		if (line_no > 0)
			printf("Files Identical\n");
		else {
			fprintf(stderr, "Empty files or other IO error\n");
			exit(1);
		}
	}

	exit(0);
}
