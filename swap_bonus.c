/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:41:59 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/09 18:57:27 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swap(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	sa(t_node **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	swap(stack);
}

void	sb(t_node **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	swap(stack);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	if ((!(*stack_a) || !(*stack_a)->next) && (!(*stack_a)
			|| !(*stack_a)->next))
		return ;
	sa(stack_a);
	sb(stack_b);
}
