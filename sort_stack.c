/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 05:06:51 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/07 06:27:40 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_value(t_node *stack_b)
{
	int	i;
	int	j;
	int	max;

	max = (stack_b)->value;
	i = 0;
	j = 0;
	while (stack_b)
	{
		if (max < stack_b->value)
		{
			max = stack_b->value;
			j = i;
		}
		i++;
		stack_b = stack_b->next;
	}
	return (j);
}

int	ft_is_small(t_node *stack, int *arr, int index)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		if (stack->value <= arr[i])
			return (1);
		i++;
	}
	return (0);
}

void	push_to_stack_b(t_node **stack_a, t_node **stack_b, int *arr, int size)
{
	int (start), (end);
	start = 0;
	end = size / 6;
	if (size > 100)
		end = size / 14;
	while (*stack_a)
	{
		if (ft_is_small(*stack_a, arr, start))
		{
			push_b(stack_a, stack_b);
			rb(stack_b);
			increment(&start, &end, &size);
		}
		else if (ft_is_small(*stack_a, arr, end))
		{
			push_b(stack_a, stack_b);
			if (*stack_b && (*stack_b)->next
				&& (*stack_b)->value < (*stack_b)->next->value)
				sb(stack_b);
			increment(&start, &end, &size);
		}
		else
			ra(stack_a);
	}
	push_back_to_stack_a(stack_a, stack_b);
}

void	increment(int *start, int *end, int *size)
{
	if (*end < *size - 1)
		(*end)++;
	if (*start < *end)
		(*start)++;
}

void	push_back_to_stack_a(t_node **stack_a, t_node **stack_b)
{
	int (max_position), (size_b);
	max_position = 0;
	size_b = 0;
	while (*stack_b)
	{
		size_b = ft_lstsize(*stack_b);
		max_position = find_max_value(*stack_b);
		if (max_position <= size_b / 2)
		{
			while (max_position > 0)
			{
				rb(stack_b);
				max_position--;
			}
		}
		else
		{
			while (max_position < size_b)
			{
				rrb(stack_b);
				max_position++;
			}
		}
		push_a(stack_a, stack_b);
	}
}
