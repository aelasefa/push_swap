#include "push_swap.h"

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
	//t_node	*stack_b = NULL;
	int	size;
	int	i;
	int	*arr;

	size = ac - 1;
	arr = malloc(sizeof(int) * size);
	i = 0;
	av[1] = ft_generate_argv(ac, av);
	printf("----------->%s<----------\n", av[1]);
	while (i < size)
	{
		arr[i] = ft_atoi(av[i + 1]);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		if (!is_valide_number(av[i]) || is_duplicates(arr, size))
		{
			printf("Error\n");
			return (1);
		}
		add_node_in_top(&stack_a, ft_atoi(av[i]));
		i++;
	}
	printf("stack a:\n");
	print_stack(stack_a);
}
