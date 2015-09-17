struct tnode *talloc(void);
char *str_dup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int line_no)
{
	int cond;

	if (p == NULL) {		/* a new word has arrived */
		p = talloc();		/* made a new node */
		p->word  = str_dup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0) {
		p->count++;		/* repeated word */
	} else if (cond< 0) 	/* less than into left sub tree */
		p->left = addtree(p->left, w, line_no);
	else				/* greater than into right subtree */
		p->right = addtree(p->right, w, line_no);
	return p;
}
