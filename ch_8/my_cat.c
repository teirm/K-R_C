#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "syscalls.h"
#define PERMS 0666

/* my_cat: concatenate files, version 1 */
int main(int argc, char *argv[])
{
//	FILE *fp;
	int fd;
	void filecopy(int, int);
	char *prog = argv[0];

	if (argc == 1) /* no args; copy standard input */
		filecopy(0, 1); /* stdin, stdout */
	else
		while (--argc > 0)
			if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
				fprintf(stderr, "%s: can't open %s\n", prog, *argv);
				exit(1);
			} else {
				filecopy(fd, 1);
				//fclose(fp);
			}
	if (ferror(stdout)) {
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}

	exit(0);
}

/* filecopy: copy file ifp to file ofp */
void filecopy(int inf, int ofp)
{
	char c;

	while (read(inf, &c, 1) == 1)
		write(ofp, &c, 1);
}
