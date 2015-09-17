struct tnode *talloc(void);
char *str_dup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree_2(struct tnode *p, char *w, int n_comp)
{
	int cond;

	if (p == NULL) {		/* a new word has arrived */
		p = talloc();		/* made a new node */
		p->word  = str_dup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strncmp(w, p->word, n_comp)) == 0)
		p->count++;		/* repeated word */
	else if (cond < 0) 	/* less than into left sub tree */
		p->left = addtree_2(p->left, w, n_comp);
	else				/* greater than into right subtree */
		p->right = addtree_2(p->right, w, n_comp);
	return p;
}

