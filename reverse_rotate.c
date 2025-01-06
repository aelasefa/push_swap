/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:49:06 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/05 06:29:38 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    reverse_rotate(t_node   **stack)
{
	if (!stack || !(*stack)->next)
		return ;
        t_node  *b_last;
        t_node  *last;

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
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void    rra(t_node **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrr(t_node **stack)
{
	rra(stack);
	rrb(stack);
	write(1, "rrr\n", 4);
}
