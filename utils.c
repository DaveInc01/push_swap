#include "header.h"

void	ft_lstadd_front(t_data **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
