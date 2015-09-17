struct lnode {				/* the linked-list node: */
	int line_no;			/* line number */
	struct lnode *next;		/* next node in list */
};

struct tnode {			/* the tree node: */
	char *word;				/* points to the text */
	int count;				/* number of occurrences */
	struct lnode *head;		/* linked-list head associated with word for line numbers */	
	struct tnode *left;		/* left child */
	struct tnode *right;	/* right child */
};

