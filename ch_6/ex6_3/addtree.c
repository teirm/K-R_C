void addnode(struct tnode *, int);
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
		p->head = NULL;
		addnode(p, line_no);
	} else if ((cond = strcmp(w, p->word)) == 0) {
		p->count++;		/* repeated word */
		addnode(p, line_no);
	} else if (cond < 0) 	/* less than into left sub tree */
		p->left = addtree(p->left, w, line_no);
	else				/* greater than into right subtree */
		p->right = addtree(p->right, w, line_no);
	return p;
}

/* addnode: add ll node with line_no */
void addnode(struct tnode *p, int line_no)
{
	struct lnode *np; 
	struct lnode *current_node = p->head;

	while (current_node != NULL && current_node->next != NULL)
		current_node = current_node->next;

	np = (struct lnode *) malloc(sizeof(struct lnode));
	np->line_no = line_no;
	np->next = NULL;

	if (current_node == NULL)
		p->head = np;	
	else
		current_node->next=np;
}
