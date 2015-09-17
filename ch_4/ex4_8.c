char buf;			/* buffer for ungetch */
int bufp = 0; 		/* next free position in buf */

int getch(void) /* get a (possibly pushed back) */
{
	int temp = buf;	

	if (buf == -99)
		return getchar();
	else {
		buf = -99;
		return temp;
	}

}

void ungetch(int c) /* push character back on input */
{
		buf = c;
}

