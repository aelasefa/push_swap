/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:41:59 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/02 20:53:29 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    swap(t_node **stack)
{
        t_node  *tmp;

        if (!stack)
                return;
        tmp = (*stack)->next;
        (*stack)->next = (*stack)->next->next;
        tmp->next = *stack;
        *stack = tmp;
}

void	sa(t_node **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack)
{
	swap(stack);
        write(1, "sb\n", 3);
}

void	ss(t_node **stack)
{
	sa(stack);
	sb(stack);
	write(1, "ss\n", 3);
}
