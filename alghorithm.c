#include "header.h"

int lst_order(t_list *list, int data)
{
	int i;

	i = 0;
	while (list->data != data)
	{
		list = list->next;
		i++;
	}
	return(i);
}

void	swap_3_elem(t_data *list)
{
	int max_order;

	max_order = lst_order(list->a, 2);
	if (max_order == 0)
	{
		rotate_a(list, 1);
		if(list->a->data == 1)
			swap_a(list, 1);
	}
	else if (max_order == 1)
	{
		rrotate_a(list, 1);
		if (list->a->data == 1)
			swap_a(list, 1);
	}
	else if (max_order == 2)
		swap_a(list, 1);
}



int lst_last(t_list *list)
{
	while(list->next)
		list = list->next;
	return (list->data);
}

void stack_to_a(t_data *list, int arg_count)
{
	int	lst_max;
	int lst_max_pos;

	while (list->b)
	{
		lst_max = ft_list_max(list->b);
		lst_max_pos = lst_order(list->b, lst_max);
		if (lst_max == list->b->data)
			push_a(list);
		else if(lst_max_pos > (arg_count / 2))
		{
			// kaxvac dirqi hanel verev kam ijacnel nerqev
			rrotate_b(list, 1);
		}
		else
			rotate_b(list, 1);
	}
}

void	butterfly(t_data *list, int n, int arg_count)
{
	int	counter;
	int lst_max;
	counter = 0;
	while(list->a)
	{
		if(list->a->data <= counter)
		{
			push_b(list);
			rotate_b(list, 1);
			counter++;
		}
		else if(list->a->data <= counter + n)
		{
			push_b(list);
			counter++;
		}
		else
			rotate_a(list, 1);
	}
		stack_to_a(list, arg_count);
}
