#include "push_swap.h"

static t_node	*ft_creat_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = (NULL);
	return (node);
}

void	add_node_in_top(t_node **stack, int value)
{
	t_node *node;

	node = ft_creat_node(value);
	if (!node)
		return ;
	node->next = *stack;
	*stack = node;
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_valide_number(char *str)
{
	int	nb;
	int	int_min;
	int	int_max;
	int	i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while(str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	int_min = 2147483649;
	int_max = 2147483647;
	nb = ft_atoi(str);
	if (nb < int_min || nb > int_max)
		return (0);
	return (1);
}

int	is_duplicates(int *arr, int size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
