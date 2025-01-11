/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:46:42 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/09 19:10:08 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*first;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	first = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	ra(t_node **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	rotate(stack);
}

void	rb(t_node **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	rotate(stack);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	if ((!(*stack_a) || !(*stack_a)->next) && (!(*stack_a)
			|| !(*stack_a)->next))
		return ;
	ra(stack_a);
	rb(stack_b);
}
