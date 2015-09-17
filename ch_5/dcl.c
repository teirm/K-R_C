#define IO_ERROR -1 /* An error in the user input */

/* dcl: parse a declarator */
int dcl(void)
{
	int ns;
	int return_check;

	for (ns = 0; gettoken() == '*'; ) 	/* count *'s */
		ns++;
	
	return_check = dirdcl();

	if (return_check == IO_ERROR)
		return IO_ERROR;

	while (ns-- > 0)
		strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
int dirdcl(void)
{
	int type;

	int return_check;

	if (tokentype =='(') { 		/* ( dcl ) */
		return_check = dcl();

		if (return_check == IO_ERROR)
			return IO_ERROR; 

		if (tokentype != ')') {
			printf("error: missing )\n");
			return IO_ERROR;	
		}
	} else if (tokentype == NAME)	/* variable name */
		strcpy(name, token);
	else {
		printf("error: expected name or (dcl)\n");
		return IO_ERROR;	
	}
	while ((type=gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			strcat(out, " function returning");
		else if (type == IO_ERROR)
			return IO_ERROR;
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
}
