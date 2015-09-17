#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "bintree.h"

#include "getword.c"
#include "tree_mem.c"
#include "addtree_2.c"
#include "treeprint.c"

#define MAXWORD 100
#define VAR_LINE 1

struct tnode *addtree_2(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);

int main(int argc, char *argv[])
{
	int n_comp, line_status;	/* flags a line as one that contains variable names */
	char word[MAXWORD];
	struct tnode *root;	

	if (argc != 2) {
		printf("Usage: ex6_2 num, where num is the string comparison length\n");
		return -1;
	}

	n_comp = atoi(argv[1]);	

	root = NULL;
	while (getword(word, MAXWORD) != EOF) {
		if (!strcmp(word, "struct") || !strcmp(word, "char") || !strcmp(word, "int") || !strcmp(word, "double") || !strcmp(word, "float"))
			line_status = VAR_LINE;
		else if (!strcmp(word, ";"))
				line_status = 0;
		else if (isalpha(word[0]) && line_status == VAR_LINE)	
			root = addtree_2(root, word, n_comp);	
	}
	treeprint(root);
	return 0;
}
