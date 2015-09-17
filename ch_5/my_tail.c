#include <stdio.h>
#include <string.h>
#include "atoi.c"
#include "get_line.c"
#include "alloc.c"

#define DEFAULT 10 /* default number of lines to print */
#define ERROR -1   /* ERROR in input */
#define MAXLINES 1000 /* Maximum number of lines stored at any given time */
int get_input(char *lines[], int nl);
void print_tail(char *lines[], int rs, int nl);
void clear_lines(char *lines[]);

/* NOTE 10 AUGUST 2015: there are several ways to improve this program using
    stdlib:
		1) malloc() can be used to generate what is called
		   lineptr here regardless of how large the requested
		   tail is (assuming there is heap space)
		2) getline() can be used to fetch lines from the terminal
		   input (I do not recall what is the stream number for 
		   this)
*/


/* my_tail: program that outputs last n lines 
	of input */
int main(int argc, char *argv[])
{

	int i, c, nb, nc;
	int end_lines = 0; /* number of lines to print from end of input */
	int read_start;

	char *arg_str;
	char *lineptr[MAXLINES];

	end_lines = DEFAULT;

	while (--argc > 0 && ((c = (*++argv)[0]) == '-'))
		switch(c) {
			case '-': /* col_start */
				arg_str = ++argv[0];
					
				end_lines = atoi(arg_str);
				break;
			default:
				printf("tail: illegal option %c\n", c);
				argc = ERROR;
				break;
		}

		if (end_lines >= MAXLINES) {
			printf("ERROR: REQUESTED TAIL TOO LARGE\n");
			return -1;
		}
		else {
			read_start = get_input(lineptr, end_lines);
			print_tail(lineptr, read_start, end_lines);	
		}
		return 0;
}

#define MAXLEN 1000 /* max length of any input line */

int get_line(char s[], int lim);
char *alloc(int n);
void afree(char *p);

int get_input(char *lineptr[], int nl)
{
	int len, nlines, array_pos;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0)
		if (nlines >= MAXLINES || (p = alloc(len)) == NULL) 
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			array_pos = nlines%nl;	
			lineptr[array_pos] = p;
			nlines++;		
		}

	return nlines;
}

void print_tail(char *lineptr[], int rs, int nl)
{
	int i;

	for (i = 0; i < nl; i++)
		printf("%s\n", lineptr[rs++%nl]);
}

void clear_lines(char *lineptr[])
{
	int i;

	for (i = 0; i < MAXLINES; i++)
		lineptr[i] = NULL;
}
