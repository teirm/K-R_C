#include "lexi_sort.h"

char *lineptr[MAXLINES];	/* pointers to text lines */
		
/* sort input lines */
int main(int argc, char *argv[])
{
	int nlines;			/* number of input lines read */
	int numeric = 0;	/* 1 if numeric sort */
	int reverse = 0;	/* 1 if reverse sort */
	int fold 	= 0;	/* 1 if fold sort (ignore case differences) */	
	int dict	= 0;	/* 1 if directory sort (compare only letters, numbers, and blanks */	
	int c;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
			case 'r':
				reverse = 1;
				break;
			case 'n':
				numeric = 1;
				break;
			case 'f':
				fold = 1;
				break;
			case 'd':
				dict = 1;
				break;
			default:
				printf("lexi_sort: illegal option %c\n", c);
				break;
			}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		my_qsort((void **) lineptr, fold, dict, 0, nlines-1,
				(int (*)(void*,void*, int, int))(numeric ? numcmp : my_strcmp));
		writelines(lineptr, nlines, reverse);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
	
}

/* my_qsort: sort v[left]...v[right] into increasing order */
void my_qsort(void *v[], int fold, int dict, int left, int right, int (*comp)(void *, void *, int, int))
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left], fold, dict) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	my_qsort(v, fold, dict, left, last-1, comp);
	my_qsort(v, fold, dict, last+1, right, comp);
}
