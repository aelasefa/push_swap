/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:02:10 by ayelasef          #+#    #+#             */
/*   Updated: 2024/12/27 15:02:47 by ayelasef         ###   ########.fr       */
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
	t_node *node;

	node = ft_creat_node(value);
	if (!node)
		return ;
	node->next = *stack;
	*stack = node;
}
