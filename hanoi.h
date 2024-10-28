#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_HEIGHT		63		/* 64 is possible but makes code messy */
#define TOWERS			3		/* Make a fun yourself */
#define TOP(x)			(tow+((x)-1))->head->val
#define BOTTOM(x)		(tow+((x)-1))->z->val
#define clear()			system("clear")

typedef struct node {
	struct node		*next;
	int				val;
} node;

typedef struct tower {
	node	*head;
	node	*z;
} tower;

void		get_number(int *n, int max);
uint64_t	mcount(int n);
void		buf_clear(void);

void		tower_init(tower *p);
void 		tower_print(tower *p, int hold, int last);
void 		tower_free(tower *p);
void 		push(tower *p, int n, int val);
int			pop(tower *p, int n);
