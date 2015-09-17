#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100 /* maximum length of a file name */

int main(int argc, char *argv[])
{
	FILE *ifp, *ofp;
	void filecopy(FILE *, FILE *);
	int  file_counter=0;	
	char file_name[MAX_LEN];
	char *prog = argv[0];

	if (argc == 1) /* no args; copy standard input */
		fprintf(stderr, "Usage: ./%s file1 file2 ...\n", prog);	
	else
		while (--argc > 0)
			if ((ifp = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "%s: can't open %s\n", prog, *argv);
				exit(1);
			} else {
				sprintf(file_name, "file_%d", file_counter);
				ofp = fopen(file_name, "w");
				fprintf(ofp, "Page\t%d\n\n", file_counter++);	
				filecopy(ifp, ofp);
				fclose(ifp);
				fclose(ofp);
			}
	if (ferror(stdout)) {
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}

	exit(0);
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}
