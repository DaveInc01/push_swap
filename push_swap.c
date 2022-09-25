#include "header.h"

int main(int argc, char **argv)
{
	t_list *first, *sec, *third, *forth, *curr;
	t_data data;
	first->data = 1;
	first->next = sec;
	sec->data = 2;
	sec->next = third;
	third->data = 3;
	third->next = forth;
	forth->data = 4;
	forth->next = NULL;
	curr = first;
	while(curr->next)
	{
		printf("%ld", curr->data);
		curr = curr->next;
	}
	return 0;
}
