#include <ctype.h>

int my_strcmp(char *s, char *t, int fold, int dict)
{
	if (dict == 1) { /* if dict mode on skip any non-alphanumeric/non-space at beginning */
		while(!isalnum(*s) && !isspace(*s))
			s++;
		while(!isalnum(*t) && !isspace(*t))
			t++;
	}

	if (fold == 1) {
		for ( ; toupper(*s) == toupper(*t); s++, t++)
			if (dict == 1 && *s != '\0' && (!isalnum(*s) && !isspace(*s)))
				s++;
			if (dict == 1 && (!isalnum(*t) && !isspace(*t)))
				t++;
			if (*s == '\0')
				return 0;
		return toupper(*s) - toupper(*t);
	}

	for ( ; *s == *t; s++, t++)
		if (dict == 1 && *s != '\0' && (!isalnum(*s) && !isspace(*s)))
			s++;
		if (dict == 1 && (!isalnum(*t) && !isspace(*t)))
			t++;
		if (*s == '\0')
			return 0;
	return *s - *t;

}
