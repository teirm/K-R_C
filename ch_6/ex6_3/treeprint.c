void nodeprint(struct lnode *);

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s", p->count, p->word);
		nodeprint(p->head);		
		treeprint(p->right);
	}
}

void nodeprint(struct lnode *np) 
{
	while (np != NULL) {
		printf(" %d ", np->line_no);
		np = np->next;
	}
	printf("\n");
}
