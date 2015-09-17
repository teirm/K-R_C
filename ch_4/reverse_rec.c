#include <stdio.h>
#include <string.h>

#define START_REV 0	/* index in string s at which to begin the reverse */

void reverse_rec(char [], int, int);
void swap(char [], int, int);

/* reverse_rec: reverse a string in place recursively */
void reverse_rec(char s[], int low, int high)
{
	if ((low+1) < (high-1)) 
		reverse_rec(s, low+1, high-1); 
	swap(s, low, high);
}

/* swap: in string s exchanges char at s[i] with char at s[j] */
void swap(char s[], int low, int high)
{
	int temp;

	temp = s[high];
	s[high] = s[low];
	s[low] = temp;
}

int main()
{
	char s[] = "abcdefghijklmnopqrstuvwxyz";

	reverse_rec(s, START_REV, strlen(s)-1);

	printf("%s\n",s);
}
