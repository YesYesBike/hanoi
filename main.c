#include <stdio.h>
#include "hanoi.h"

void hanoi(int n)
{
	tower tow[TOWERS];
	tower_init(tow);
	for (int i=n; i>=1; i--)
		push(tow, 0, i);

	int hold = 0;
	int last = 0;
	int count = 0;

	uint64_t min_count = (1 << n) + 0xFFFFFFFF;		//1<<64 is 1 not 0 lol
	for (;;) {
		int target;
		tower_print(tow, hold, last);
		
		if (hold == 0) {
			printf("Pick up the block from the tower.\n");
			for (;;) {
				get_number(&target, TOWERS);
				if (TOP(target) != 0)
					break;
				printf("Tower %d is empty!\n", target);
			}
			hold = pop(tow, target-1);
			last = target;
		} else {
			printf("Put down the block to the tower.\n");
			for (;;) {
				get_number(&target, TOWERS);
				if (hold < TOP(target) || TOP(target) == 0)
					break;
				printf("You can't put the larger block.\n");
			}
			push(tow, target-1, hold);
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

	tower_print(tow, hold, last);
	printf("You cleared! (count: %d / min: %llu)\n", count, min_count);
	tower_free(tow);
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
