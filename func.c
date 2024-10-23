#include "hanoi.h"

void inline buf_clear(void)
{
	while (getchar() != '\n')
		;
}

void get_number(int *n, int max)
{
	printf("Enter the number(1-%d): ", max);
	while (scanf("%d", n) != 1 || *n < 1 || *n > max) {
		buf_clear();
		printf("Enter the right number(1-%d): ", max);
	}
}

uint64_t mcount(int n)
{
	int ret = 1;
	for (int i=2; i<=n; i++)
		ret = ret*2 + 1;

	return ret;
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

void tower_print(tower *tow, int hold, int last)
{
	clear();
	if (last != 0) {
		for (int i=0; i<=last; i++)
			printf("     ");
		printf("%d", hold);
	}
	printf("\n\n");

	printf("Top:   %4d %4d %4d\n",
			TOP(1), TOP(2), TOP(3));
	printf("Bottom:%4d %4d %4d\n",
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
	new->next = (p+n)->head;
	if ((p+n)->z->next == NULL)
		(p+n)->z = new;
	(p+n)->head = new;
}

int pop(tower *p, int n)
{
	node *rp = (p+n)->head;
	(p+n)->head = (p+n)->head->next;
	if (rp == (p+n)->z)
		(p+n)->z = (p+n)->head;
	int ret = rp->val;
	rp->next = NULL;
	free(rp);

	return ret;
}
