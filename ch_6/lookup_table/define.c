#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "getword.c"
#include "lookup.c"

#define MAXWORD 100
#define IN_STRING 1

int getword(char *, int);
unsigned hash(char *);
struct nlist *lookup(char *);
char *str_dup(char *);
struct nlist *install(char *, char *);
int undef(char *, char *);
int found_def(char *);


int main(int argc, char *argv[])
{
	int def_type;	
	int string_status;

	char word[MAXWORD];

	struct nlist *np;


	while(getword(word, MAXWORD) != EOF) {
		if (strcmp(word,"#") == 0) {
			def_type = found_def(word);	
			
			if (def_type == -1) {
				printf("ERROR: Non-Numeric definintion not supported\n");
				return -1;
			}
		}

		if (word[0] == '"' || word[strlen(word)-1] == '"') {
			if (string_status == IN_STRING)
				string_status = 0;
			else
				string_status = IN_STRING;
		}
	
		if (string_status != IN_STRING && (np = lookup(word)) != NULL)
			printf("%s >> %s\n", word, np->defn);


	}

	return 0;
}

int found_def(char *s )
{
	
	char name[MAXWORD];
	char value[MAXWORD];
	
	getword(s, MAXWORD);
	
	if (strcmp(s,"define") == 0) {
		getword(s,MAXWORD);
		strcpy(name, s); 
		getword(s, MAXWORD);
		
		if (!isdigit(s[0])) {
			printf("ERROR: Non-Numeric definintion not supported\n");
			return -1;
		}
		strcpy(value, s);
		install(name, value); /* places entry in HASH TABLE */
	}

	return 0;
}
