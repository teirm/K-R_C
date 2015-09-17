<<<<<<< HEAD
#include <string.h>

#define BUFSIZE 100

int buf[BUFSIZE];	/* buffer for ungetch, Ex 4-9: EOF is not a char so use int size */
=======
#define BUFSIZE 100

char buf[BUFSIZE];	/* buffer for ungetch */
>>>>>>> 16622dc5f8b557529594827122d43c61edeaea87
int bufp = 0; 		/* next free position in buf */

int getch(void) /* get a (possibly pushed back) */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
<<<<<<< HEAD

/* ungets: will put an entire string back on buffer */
/* 	since the ENTIRE string should be placed back on the buffer*/
int ungets(char s[])
{
	int i = 0;	
	
	if (strlen(s) > (BUFSIZE - bufp + 1)) {
		printf("STRING WILL NOT FIT IN BUFFER");
		return -1;
	}
	else {
		for (i = 0; s[i] != '\0'; i++)
			ungetch(s[i]);
	}
}
=======
>>>>>>> 16622dc5f8b557529594827122d43c61edeaea87
