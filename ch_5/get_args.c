void get_args(void)
{
	int c;
	char *p = arguments;

	while ((c = getch()) == ' ' || c == '\t')
		;

	while (c != ')')
	{
		if(c == ',') {
			c = getch();
			continue;
		}
		*p++ = c;
		c = getch();
	}
	*p = '\0';
	ungetch(c);
}
