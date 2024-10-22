#include <stdlib.h>
#include <stdio.h>

void	clear(void);
void	get_number(int *n, int max);
int		mcount(int n);
void	buf_clear(void);

void	tower_init(tower *p);
void	tower_print(tower *p);
void	tower_free(tower *p);
void	push(tower *p, int n, int val);
int		pop(tower *p, int n);
