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
	nb = ft_atoi(str[i]);
	if (nb < –2147483648 || nb > 2147483647)
		return (0);
	return (1);
}
