/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_element_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:08:34 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/11 22:09:08 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_value(t_node *stack_a)
{
	int	i;
	int	j;
	int	min;

	min = (stack_a)->value;
	i = 0;
	while (stack_a)
	{
		if (min > stack_a->value)
		{
			min = stack_a->value;
			j = i;
		}
		i++;
		stack_a = stack_a->next;
	}
	return (j);
}

void	push_to_stack_b_(t_node **stack_a, t_node **stack_b)
{
	int (min_position), (size_a), (i);
	min_position = 0;
	size_a = 0;
	i = 1;
	while (i != 0)
	{
		size_a = ft_lstsize(*stack_a);
		min_position = find_min_value(*stack_a);
		if (min_position < size_a / 2)
		{
			while (min_position > 0)
			{
				ra(stack_a);
				min_position--;
			}
		}
		else
		{
			while (size_a > min_position++)
				rra(stack_a);
		}
		push_b(stack_a, stack_b);
		i--;
	}
}
