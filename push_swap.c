#include "header.h"

int main()
{
	t_list *head, *one, *two, *three;
	t_data *a;
	a = malloc(sizeof(t_data));
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
	a->a = head;
	// push_b(a);
	while(head)
	{
		printf("%ld\n", head->data);
		head = head->next;
	}

	return 0;
}
