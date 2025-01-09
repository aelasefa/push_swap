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

void	ft_sort_small_elment(t_node **stack_a,t_node **stack_b,int size)
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
	int		i;
	int		min;
	t_node	*current;

	i = 0;
	while (i < 2)
	{
		current = *stack_a;
		min = current->value;
		while (current)
		{
			if (current->value < min)
				min = current->value;
			current = current->next;
		}
		while ((*stack_a)->value != min)
		{
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a);
			else
				ra(stack_a);
		}
			push_b(stack_a, stack_b);
	}
	ft_sort_3_element(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	ft_sort_4_element(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->next->value)
		sa(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->next->next->value)
		sa(stack_a);
	push_b(stack_a, stack_b);
	ft_sort_3_element(stack_a);
	push_a(stack_a, stack_b);
}

void	ft_sort_3_element(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value > (*stack_a)->next->next->value)
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


