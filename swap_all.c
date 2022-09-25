#include "header.h"

void swap_ss (t_data *list)
{
	swap_a(list, 0);
	swap_b(list, 0);

	write (1, "ss\n", 3);
}
