/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:02:10 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/07 05:49:19 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_creat_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = (NULL);
	return (node);
}

void	add_node_in_top(t_node **stack, int value)
{
	t_node	*node;
	t_node	*ptr;

	node = ft_creat_node(value);
	if (!node)
	{
		*stack = NULL;
		return ;
	}
	if (!*stack)
		*stack = node;
	else
	{
		ptr = *stack;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = node;
	}
}
