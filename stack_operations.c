#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return;
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (!(*stack_a))
		printf("stack a is underflow");
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
}

void	push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	
	if (!(*stack_b))
		printf("stack b is underflow");
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
}
void	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*first;
	
	tmp = *stack;
	first = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	reverse_rotate(t_node	**stack)
{
	t_node	*b_last;
	t_node	*last;

	b_last = NULL;
	last = *stack;
	while (last->next)
	{
		b_last = last;
		last = last->next;
	}
	b_last->next = NULL;
	last->next = *stack;
	*stack = last;
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
