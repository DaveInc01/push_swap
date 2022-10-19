#include "header.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}


void rotate_a(t_data *list, int flag)
{
	t_list *first, *tmp, *sec;

	first = list->a;
	tmp = list->a;
	if (!first->next)
		return ;
	sec = first->next;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = first;
	list->a = sec;
	first->next = NULL;
	// tmp->next = NULL;
	if(flag == 1)
		write(1, "ra\n", 3);
}

void push_b(t_data *list)
{
	t_list *tmp;

	tmp = list->a;
	if(list->a->next)
		list->a = list->a->next;
	else
		list->a = NULL;
	tmp->next = NULL;
	if(list->b)
		ft_lstadd_front(&list->b, tmp);
	else
		list->b = tmp;
	// check this case when b stack is empty unexpecing seg fault!
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*iter;

	if (!*lst && !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	iter = *lst;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = new;
}


int	ft_atoi(const char *str)
{
	int	m;
	int	sum;

	sum = 0;
	m = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			m *= -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= 48 && *str <= 57)
		{
			sum = sum * 10 + (int )*str - '0';
			str++;
		}
		else
			return (m * sum);
	}
	return (m * sum);
}


int is_dublicate(int num, int *arr, int arr_size)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while(i < arr_size)
	{
		if (num == arr[i])
			return (1);
		i++;
	}
	return (0);
}

int pushing_to_arr(char *elem, int *unordered)
{
	static int i;
	int num = ft_atoi(elem);
	if (num >= 2147483647 || is_dublicate(num, unordered, i))
		return (0);
	unordered[i] = num;
	i++;
	return (1);
}

void swap_arr(int *elem1, int *elem2)
{
	int tmp;

	tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

int *order_arr(int *unordered, int size)
{
	int	i;
	int flag;

	i = 0;
	flag = 0;
	--size;
	while(i < size)
	{
		if(unordered[i] > unordered[i + 1])
		{
			flag = 1;
			swap_arr(&unordered[i], &unordered[i + 1]);
		}
		i++;
		if(i == size && flag == 1)
		{
			i = 0;
			flag = 0;
		}
	}
	return (unordered);
}


void fill_stack(t_data *list, char *elem, int *ordered_arr, int size)
{
	int	i;
	int	num;
	t_list *e;

	i = 0;
	num = ft_atoi(elem);
	while (i < size)
	{
		if (num == ordered_arr[i])
		{
			e = malloc(sizeof(t_list));
			e->data = i;
			e->next = NULL;
			if (list->a)
				ft_lstadd_back(&list->a, e);
			else
				list->a = e;
			break;
		}
		i++;
	}
}

int ft_list_max(t_list *stack)
{
	t_list	*max;
	int	i;

	i = 0;
	if (stack)
	{
		max = stack;
		while (stack->next)
		{
			if(stack->data > max->data)
				max = stack;
			stack = stack->next;
		}
		return (max->data);
	}
	else
		return (-1);
}

int main(int argc, char **argv)
{
	int		i;
	int		j;
	int		*unordered;
	int		*ordered;
	int		stack_size;
	t_data	*list;
	t_list	*tmp = NULL;

	list = malloc(sizeof(t_data));
	list->a = NULL;
	list->b = NULL;
	if (argc >= 2)
	{
		i = 1;
		stack_size = argc - 1;
		unordered = malloc(sizeof(int) * (stack_size));
		if (!unordered)
			return (0);
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				if((argv[i][j] >= '0' && argv[i][j] <= '9') || (argv[i][j] == '-') || (argv[i][j] == '+'))
					j++;
				else
				{
					write(1, "Error!\n Argument is not a number", 33);
					return (0);
				}
			}
			if(!(pushing_to_arr(argv[i], unordered)))
			{
				write(1, "Error\n", 7);
				return (0);
			}
			i++;
		}
		ordered = order_arr(unordered, stack_size);
		i = 0;
		while (++i < argc)
			fill_stack(list, argv[i], ordered, stack_size);
		int counter = 0;
		while(list->a)
		{
			if(list->a->data <= counter)
			{
				push_b(list);
				rotate_b(list, 1);
				counter++;
			}
			else if(list->a->data <= counter + 1)
			{
				push_b(list);
				counter++;
			}
			else
				rotate_a(list, 1);
		}
		// while(list->b)
		// {
		// 	ft_list_max(list->b);
		// }
		printf("max num = %d", ft_list_max(list->b));
		// tmp = list->b;
		// while(tmp)
		// {
		// 	printf("%d\t", tmp->data);
		// 	tmp = tmp->next;
		// }
		// printf("\n");
		free(unordered);
	}
	return 0;
}
