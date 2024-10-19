#include "hanoi.h"
#include "func.h"

void inline clear(void)
{
	system("clear");
}

void inline buf_clear(void)
{
	while (getchar() != '\n')
		;
}

void get_number(int *n, int max)
{
	printf("Enter the number(1-%d): ", max);
	while (scanf("%d", n) != 1) {
L_GET_NUM_AGAIN:
		buf_clear();
		printf("Enter the right number(1-%d): ", max);
	}

	if (*n < 1 || *n > max)
		goto L_GET_NUM_AGAIN;
}


void tower_init(tower *p)
{
	for (int i=0; i<TOWERS; i++) {
		(p+i)->head = malloc(sizeof(node));
		(p+i)->z = (p+i)->head;
		(p+i)->z->val = 0;
		(p+i)->z->next = NULL;
	}
}

void inline tower_print(tower *tow)
{
	clear();
	printf("Top:    %4d %4d %4d\n",
			TOP(1), TOP(2), TOP(3));
	printf("Bottom: %4d %4d %4d\n",
			BOTTOM(1), BOTTOM(2), BOTTOM(3));
}

void tower_free(tower *p)
{
	for (int i=0; i<TOWERS; i++) {
		node *rp = (p+i)->head->next;
		while (rp != NULL) {
			(p+i)->head->next = rp->next;
			rp->next = NULL;
			free(rp);
			rp = (p+i)->head->next;
		}
		free((p+i)->head);
	}
}

void push(tower *p, int n, int val)
{
	node *new = malloc(sizeof(node));
	new->val = val;
	new->next = (p+n-1)->head;
	if ((p+n-1)->z->next == NULL)
		(p+n-1)->z = new;
	(p+n-1)->head = new;
}

int pop(tower *p, int n)
{
	node *rp = (p+n-1)->head;
	(p+n-1)->head = (p+n-1)->head->next;
	if (rp == (p+n-1)->z)
		(p+n-1)->z = (p+n-1)->head;
	int ret = rp->val;
	rp->next = NULL;
	free(rp);

	return ret;
}
