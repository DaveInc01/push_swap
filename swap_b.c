#include "header.h"

void swap_b(t_data *list, int flag)
{
	t_list *tmp;
	long int t;

	tmp = list->b;

	if (!list->b->next)
		return ;
	t = list->b->next->data;
	list->b->next->data = tmp->data;
	list->b->data = t;
	if (flag == 1)
		write(1, "sb\n", 3);
}
