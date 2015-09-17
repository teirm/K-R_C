#include <stdio.h>

/* ptr_strindex: returns the index of t in s, or -1 if none */
int ptr_strindex(char *s, char *t)
{
	int i, j, k;

		for (i = 0; *(s+i) != '\0'; i++) {
			for (j = i, k = 0; *(t+k) != '\0' && *(s+j) == *(t+k); j++, k++)
				;
			if (k > 0 && t[k] == '\0')
				return i;
		}
		return -1;
}

/* driver for ptr_strindex */
int main()
{
	char *s = "DogCatDog";
	char *t = "Cat";

	printf("%d\n", ptr_strindex(s,t));
}
