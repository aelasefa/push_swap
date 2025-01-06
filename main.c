#include "push_swap.h"

void	free_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

int	is_sorted(t_node *stack_a)
{
	t_node *node;

	node = stack_a;
	while(node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d -> ", stack->value);
		stack = stack->next;
	}
	printf ("NULL\n");
}

int main(int ac, char** av)
{
	t_node	*stack_a = NULL;
	t_node	*stack_b = NULL;
	int	size;
	int	*arr;
	int	*arr_sorted;
	check_add(&stack_a, ac, av);
	if (!is_sorted(stack_a))
	{
		size = ft_lstsize(stack_a);
		arr = push_element_in_arr(&stack_a, size);
		arr_sorted = sort_arr(arr, size);
		push_to_stack_b(&stack_a, &stack_b, arr_sorted, size);
	}
}
