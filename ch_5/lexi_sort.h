#include <stdio.h>
#include <string.h>
#include "numcmp.c"
#include "swap.c"
#include "get_line.c" 
#include "alloc.c"
#include "read_write_lines.c"
#include "my_strcmp.c"

#define MAXLINES 5000		/* max #lines to be sorted */

void my_qsort(void *lineptr[], int fold, int dict, int left, int right,
		int (*comp)(void *, void *, int, int));
int numcmp(char *, char *, int fold, int dict);
int my_strcmp(char *, char *, int fold, int dict);
int get_line(char s[], int lim);
