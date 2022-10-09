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

void push_b(t_data *list)
{
	t_list *tmp;

	tmp = list->a;
	if(list->a->next)
		list->a = list->a->next;
	tmp->next = NULL;
	if(list->b)
		ft_lstadd_front(&list->b, tmp);
	else
		list->b = tmp;
	// check this case when b stack is empty unexpecing seg fault!
}

void rotate_b(t_data *list, int flag)
{
	t_list *first;
	t_list *tmp;

	first = list->b;
	tmp = list->b;
	if (!(first->next))
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = first;
	list->a = tmp->next;
	tmp->next = NULL;
	if(flag == 1)
		write(1, "rb\n", 3);
}


void rrotate_b(t_data *list, int flag)
{
	t_list *first;
	t_list *last;
	t_list *tmp;

	first = list->b;
	tmp = list->b;
	last = NULL;
	if (!(first->next))
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	last->next = first;
	list->b = last;
	tmp->next = NULL;
	if (flag == 1)
		write (1, "rrb\n", 4);
}
