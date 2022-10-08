#include "header.h"

void swap_ss (t_data *list)
{
	swap_a(list, 0);
	swap_b(list, 0);
	write (1, "ss\n", 3);
}

void rotate_all (t_data *list)
{
	rotate_a(list, 0);
	rotate_b(list, 0);
	write(1, "rr\n", 3);
}

void rrotate_all (t_data *list)
{
	rrotate_a(list, 0);
	rrotate_b(list, 0);
	write(1, "rrr\n", 4);
}
