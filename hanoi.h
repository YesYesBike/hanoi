#define MAX_HEIGHT		11
#define TOWERS			3
#define TOP(x)			(tow+((x)-1))->head->val
#define BOTTOM(x)		(tow+((x)-1))->z->val

typedef struct node {
	struct node		*next;
	int				val;
} node;

typedef struct tower {
	node *head;
	node *z;
} tower;


void hanoi(int n);
