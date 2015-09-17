#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "bintree.h"

#include "getword.c"
#include "tree_mem.c"
#include "addtree.c"
#include "treeprint.c"

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int, int *);

/* word frequency count */
int main(int argc, char *argv[])
{
	int line_no = 1; 								
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD, &line_no) != EOF) {
		if (isalpha(word[0]))
			root = addtree(root, word, line_no);
	}
	
	treeprint(root);
	
	return 0;
}
