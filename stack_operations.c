#include "push_swap.h"

void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
}

void	push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
}

t_node	*pop(t_node *stack)
{
	t_node	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	stack = stack->next;
	free(tmp);
	return (stack);
}
