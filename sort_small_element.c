/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:46:20 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/09 00:36:07 by ayelasef         ###   ########.fr       */
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
		if (min_position < size_a/2)
		{
			while (min_position > 0)
			{
				ra(stack_a);
				min_position--;
			}
		}
		else
		{
			while (min_position < size_a)
			{
				rra(stack_a);
				min_position++;
			}
		}
		push_b(stack_a, stack_b);
		i--;
	}
}

void	ft_sort_small_elment(t_node **stack_a, t_node **stack_b, int size)
{
	if (size == 2)
		ft_sort_2_element(stack_a);
	else if (size == 3)
		ft_sort_3_element(stack_a);
	else if (size == 4)
		ft_sort_4_element(stack_a, stack_b);
	else if (size == 5)
		ft_sort_5_element(stack_a, stack_b);
}

void	ft_sort_5_element(t_node **stack_a, t_node **stack_b)
{
	push_to_stack_b_(stack_a, stack_b);
	ft_sort_4_element(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	ft_sort_4_element(t_node **stack_a, t_node **stack_b)
{
	push_to_stack_b_(stack_a, stack_b);
	ft_sort_3_element(stack_a);
	push_a(stack_a, stack_b);
}

void	ft_sort_3_element(t_node **stack_a)
{
	if (is_sorted(*stack_a))
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value)
		ra(stack_a);
	if ((*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	ft_sort_2_element(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}
