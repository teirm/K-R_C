#include <stdio.h>

/* my_strlen */
int my_strlen(char *s)
{
	int n = 0;	
	while (*s++)
		n++;
	return --n;
}

/* exercise 5-3: pointer version of strcat */
void my_strcat(char *s, char *t)
{
	while (*s++);
	s--;
	while (*s++ = *t++);
}

/* exercise 5-4: checks if string t occurs at end of string s */ int strend(char *s, char *t)
{
	int diff;
	if((diff = (my_strlen(s)-my_strlen(t))) >= 0) {
		*s+=diff;
		while (*s++ == *t++) {
			if (*s == '\0')
				return 1;
		}
	}
	return 0;
}	

/* n_cat: concat first n characters of t to s */
void n_cat(char *s, char *t, int n)
{
	int i;	
	if (my_strlen(t) >= n) {
		while (*s++);
		s--;
	
//		while (*s++ = *t++ && n-- > 0); why does this not work?
		
		for (i = 0; i < n; i++)
			*s++ = *(t+i);
		*s = '\0';
	}
	else
		printf("n larger than input");
}

/* n_copy: copy first n characters of t into s */
void n_copy(char *s, char *t, int n)
{
	int i;
	if (my_strlen(t) >= n) {
		for (i = 0; i < n; i++)
			*s++ = *t++;
		*s = '\0';	
	}
	else
		printf("n larger than input");
}

/* n_cmp: compare the first n characters of n to s */
int n_cmp (char *s, char *t, int n)
{
	for ( ; *s == *t && n > 0; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

int main()
{
	char s[] = "Dog";  /* a pointer to a STRING CONSTANT IS IMMUTABLE >> SEGFAULT */
	char t[] = "Cat";
//	my_strcat(s,t);
//	printf("%s\n",s);

//	printf("%d\n", strend(s,t));
//	n_cat(s,t,2);	
//	printf("%s\n", s);

	printf("%d\n", n_cmp(s,t,1));
}
