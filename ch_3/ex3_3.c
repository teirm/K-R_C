#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000 /* maximum size of a string */

void expand (char s1[], char s2[])
{
	int i = 0;
	int j = 0;
	int k = 0;
	char range_end;

	
	while(s1[i] != '\0') {
		if (s1[i] == 45 && (i==0 || i==strlen(s1)-1)) { /* -1 because string is indexed from zero */
			s2[k++] = s1[i];
			i++;	
		}
		else if (s1[i] == '-') {
			i++;
		}
		else if (s1[i] >= 48 && s1[i] <= 57) {
			for (j = s1[i]; j <= s1[i+2]; ++j) {
				if (j == range_end)
					j++;

				s2[k++]=j;
			}
			range_end = s1[i+2];
			i++;
		}
		else if (s1[i] >= 65 && s1[i] <=90) {
			for (j = s1[i]; j <= s1[i+2]; ++j) {
				if (j == range_end)
					j++;	

				s2[k++]=j;
	
			}
			range_end = s1[i+2];
			i++;
		}
		else if (s1[i] >= 97 && s1[i] <= 122) {
			for (j = s1[i]; j <= s1[i+2]; ++j) {
				if (j == range_end)
					j++;	
				
				s2[k++]=j;

			}
			range_end = s1[i+2];
			i++;	
		}

	}
	
	s2[k] = '\0';
}	

int main()
{
	char s1[] = "-a-b-yA-Z4-9-";
	char s2[MAX_LENGTH];

	expand(s1,s2);

	printf("%s expands to\n%s\n\n",s1,s2);
	printf("%d\n",strlen(s1));

	return 0;
}
