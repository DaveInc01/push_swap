# ifndef HEADER_H
# define HEADER_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list {
	int 			data;
	struct s_list	*next;
}			   t_list;

typedef struct s_data {
	t_list *a;
	t_list *b;

}				t_data;

int		ft_atoi(const char *str);
void	ft_lstadd_front (t_list **lst, t_list *new);
void 	swap_a (t_data *list, int flag);
void 	swap_b (t_data *list, int flag);
void	swap_ss (t_data *list);
void 	push_a (t_data *list);
void	push_b (t_data *list);
void 	rotate_a (t_data *list, int flag);
void 	rotate_b (t_data *list, int flag);
void 	rotate_all (t_data *list);
void 	rrotate_a (t_data *list, int flag);
void 	rrotate_b (t_data *list, int flag);
void 	rrotate_all (t_data *list);
void	ft_lstadd_back(t_list **lst, t_list *new);

# endif
