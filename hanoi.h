#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_HEIGHT		64		/* UNSIGNED LONG LONG */
#define TOWERS			3		/* Make a fun yourself */

#define TOP_IDX(x)		tow[(x)][0]
#define TOP(x)			tow[(x)][TOP_IDX(x)]
#define BOTTOM(x)		tow[(x)][1]
//#define TOP(x)			(tow+((x)-1))->head->val
//#define BOTTOM(x)			(tow+((x)-1))->z->val
#define clear()			system("clear")

/* tower as a linked list
typedef struct node {
	struct node		*next;
	int				val;
} node;

typedef struct tower {
	node	*head;
	node	*z;
} tower;
*/

void		get_number(int *n, int max);
uint64_t	mcount(int n);
void		buf_clear(void);

/* linked list
void		tower_init(tower *p);
void 		tower_free(tower *p);
void 		push(tower *p, int n, int val);
int			pop(tower *p, int n);
*/

void		tower_print(int tow[][MAX_HEIGHT+1], int hold, int last);
void		push(int tow[][MAX_HEIGHT+1], int n, int val);
int			pop(int tow[][MAX_HEIGHT+1], int n);
