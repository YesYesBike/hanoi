#include <stdio.h>
#include "hanoi.h"
#include "func.h"

int hold = 0;
int last = 0;
int count = 0;

void hanoi(int n)
{
	tower tow[TOWERS];
	tower_init(tow);
	for (int i=n; i>=1; i--)
		push(tow, 1, i);

	extern int hold;
	extern int last;
	int min_count = mcount(n);
	for (;;) {
		int target;
		tower_print(tow);
		
		if (hold == 0) {
			printf("Pick up the block from the tower.\n");
L_PICK_ENTER_AGAIN:
			get_number(&target, TOWERS);
			if (TOP(target) == 0) {
				printf("Tower %d is empty!\n", target);
				goto L_PICK_ENTER_AGAIN;
			}
			hold = pop(tow, target);
			last = target;
		} else {
			printf("Put down the block to the tower.\n");
L_PUT_ENTER_AGAIN:
			get_number(&target, TOWERS);
			if (hold > TOP(target) && TOP(target) != 0) {
				printf("You can't put the larger block.\n");
				goto L_PUT_ENTER_AGAIN;
			}
			push(tow, target, hold);
			hold = 0;
			last = 0;
			count++;

			//MOVE TO THE THIRD TOWWWWWER
			//if (TOP(1) == 0 && TOP(3) == 0)
			//	break;
			if (TOP(1) == 0 && TOP(2) == 0)
				break;
		}
	}

	tower_print(tow);
	printf("You cleared! (count: %d / min: %d)\n", count, min_count);
	count = 0;
	tower_free(tow);
	buf_clear();
}

int main(void)
{
	for (;;) {
		clear();
		int n;
		printf("HANOI TOWER\n");
		get_number(&n, MAX_HEIGHT);
		hanoi(n);
		printf("Play again? (y/n)\n> ");
		if (getchar() == 'n') {
			break;
		} else {
			buf_clear();
			continue;
		}
	}
	

	return 0;
}
