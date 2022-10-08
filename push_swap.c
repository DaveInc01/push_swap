#include "header.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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
}

int main()
{
	t_list *head, *one, *two, *three, *tmp;
	t_data *stack;
	stack = malloc(sizeof(t_data));
	one = malloc(sizeof(t_list));
	two = malloc(sizeof(t_list));
	three = malloc(sizeof(t_list));
	one->data = 1;
	one->next = two;
	two->data = 2;
	two->next = three;
	three->data = 3;
	three->next = NULL;
	head = one;
	stack->a = head;
	push_b(stack);
	tmp = stack->b;
	while(tmp)
	{
		printf("%ld\n", tmp->data);
		tmp = tmp->next;
	}
	return 0;
}
