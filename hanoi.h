#include <stdlib.h>
#include <stdio.h>

#define MAX_HEIGHT		9999	/* It's hard enough */
#define TOWERS			3		/* Make a fun yourself */
#define TOP(x)			(tow+((x)-1))->head->val
#define BOTTOM(x)		(tow+((x)-1))->z->val

typedef struct node {
	struct node		*next;
	int				val;
} node;

typedef struct tower {
	node	*head;
	node	*z;
} tower;

void clear(void);
void get_number(int *n, int max);
void buf_clear(void);

void tower_init(tower *p);
void tower_print(tower *p);
void tower_free(tower *p);
void push(tower *p, int n, int val);
int pop(tower *p, int n);
