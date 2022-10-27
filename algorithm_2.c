#include "header.h"

void	swap_4_elem(t_data *list)
{
	if (list->a->next->data == 3)
		swap_a(list, 1);
	while (list->a->data != 3)
		rrotate_a(list, 1);
	/* push the max elem to b stack */
	push_b(list);
	swap_3_elem(list);
	push_a(list);
	rotate_a(list, 1);
}

void	swap_5_elem(t_data *list)
{
	if (list->a->next->data == 4)
		swap_a(list, 1);
	else if(list->a->next->data == 4)
	{
		rotate_a(list, 1);
		rotate_a(list, 1);
	}
	while (list->a->data != 4)
		rrotate_a(list, 1);
	push_b(list);
	swap_4_elem(list);
	push_a(list);
	rotate_a(list, 1);
	if (list->a->data != 0)
		swap_a(list, 1);
}
