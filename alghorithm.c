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

int lst_last(t_list *list)
{
	while(list->next)
		list = list->next;
	return (list->data);
}

void stack_to_a(t_data *list)
{
	int	lst_max;
	int lst_max_pos;

	while (list->b)
	{
		lst_max = ft_list_max(list->b);
		lst_max_pos = lst_order(list->b, lst_max);
		if (lst_max == list->b->data)
			push_a(list);
		else if(lst_max_pos > argCount / 2);
		{
			// kaxvac dirqi hanel verev kam ijacnel nerqev
		}
		else
		{
			rrotate_b(list, 1);
			push_a(list);
		}
	}
}

void	butterfly(t_data *list, int n)
{
	int	counter;

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
	// stack_to_a(list);
}
