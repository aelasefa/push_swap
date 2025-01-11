/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:49:06 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/09 19:09:43 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*b_last;
	t_node	*last;

	if (!stack || !(*stack)->next)
		return ;
	b_last = NULL;
	last = *stack;
	while (last->next)
	{
		b_last = last;
		last = last->next;
	}
	if (b_last)
		b_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrb(t_node **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	reverse_rotate(stack);
}

void	rra(t_node **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	reverse_rotate(stack);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if ((!(*stack_a) || !(*stack_a)->next) && (!(*stack_a)
			|| !(*stack_a)->next))
		return ;
	rra(stack_a);
	rrb(stack_b);
}
