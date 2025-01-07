/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:46:42 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/06 01:58:15 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack)
{
	ra(stack);
	rb(stack);
	write(1, "rr\n", 3);
}
