#include "header.h"


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

	i = 0;
	while(i <= arr_size)
	{
		if (num == arr[i])
			return (1);
		i++;
	}
	return (0);
}

int pushing_to_arr(char *elem, int *unordered, int stack_size)
{
	static int i;
	int num = ft_atoi(elem);
	if (num >= 2147483647 || is_dublicate(num, unordered, stack_size))
		return (0);
	unordered[i] = num;
	i++;
	return (1);
}

int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		int	i;
		int	j;
		int	*unordered;
		int stack_size;

		i = 1;
		stack_size = argc - 1;
		unordered = malloc(sizeof(int) * (stack_size));
		printf("stacksize = %d\n", stack_size);
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
					write(1, "Error\n", 6);
					return (0);
				}
			}
			if(!(pushing_to_arr(argv[i], unordered, stack_size)))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			i++;
			// order_arr(unordered)
		}
		i = 0;
		while(i < stack_size)
		{
			printf("%d\n", unordered[i]);
			i++;
		}
	}
	return 0;
}
