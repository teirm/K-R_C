/* str_len: return length of string s */
int str_len(char *s)
{
	int n;

	for (n = 0; *s != '\0'; s++)
		n ++;
	return n;
}
