#include "header.h"


void swap_a(t_data *list, int flag)
{
	t_list *tmp;
	long int t;

	tmp = list->a;

	if (!list->a->next)
		return ;
	t = list->a->next->data;
	list->a->next->data = tmp->data;
	list->a->data = t;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void push_a(t_data *list)
{
	t_list *tmp;

	tmp = list->b;
	list->b = list->b->next;
	tmp->next = NULL;
	if(list->a)
		ft_lstadd_front(&list->a, tmp);
	else
		list->a = tmp;
}

void rotate_a(t_data *list, int flag)
{
	t_list *first;
	t_list *tmp;

	first = list->a;
	tmp = list->a;
	if (!first->next)
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = first;
	list->a = tmp->next;
	tmp->next = NULL;
	if(flag == 1)
		write(1, "ra\n", 3);
}

void rrotate_a(t_data *list, int flag)
{
	t_list *first;
	t_list *last;
	t_list *tmp;

	first = list->a;
	tmp = list->a;
	last = NULL;
	if (!(first->next))
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	last->next = first;
	list->a = last;
	tmp->next = NULL;
	if (flag == 1)
		write (1, "rra\n", 4);
}
