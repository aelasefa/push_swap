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
	t_node	*stack_b = NULL;
	int	i = 1;
	while (i < ac)
	{
		add_node_in_top(&stack_a, ft_atoi(av[i]));
		i++;
	}
	/*printf("before swap:\n");
	print_stack(stack_a);
	//swap(&stack_a);
	//printf("After swap\n");
	//print_stack(stack_a);
	push_b(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	printf("stack b:\n");
	print_stack(stack_b);
	*/
	printf("stack a:\n");
	print_stack(stack_a);
	reverse_rotate(&stack_a);
	print_stack(stack_a);
}
