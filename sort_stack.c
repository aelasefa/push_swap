/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 05:06:51 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/06 05:50:10 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*push_element_in_arr(t_node **stack_a, int size)
{
	t_node *node;
	int	*arr;
	int	i;
	
	node  = *stack_a;
	arr = malloc(sizeof(int) * size);
	if (!arr)
	i = 0;
	while (node)
	{
		arr[i] = node->value;
		node = node->next;
		i++;
	}
	return (arr);
}

int	*sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	find_max_value(t_node *stack_b)
{
	int	i;
	int	j;
	int	max;

	max = (stack_b)->value;
	i = 0;
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

int	ft_is_small(t_node *stack, int *arr ,int index) 
{
	int i;
	
	i = 0;
	while (i <= index)
	{
		if (stack->value <= arr[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_lstsize(t_node *lst)
{
	int		count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	push_to_stack_b(t_node **stack_a, t_node **stack_b, int *arr, int size)
{
	int	start;
	int	end;

	start = 0;
	end = size / 6;
	if (size > 100)
		end = size/16;
	while (*stack_a)
	{
		if (ft_is_small(*stack_a, arr, start))
		{
			push_b(stack_a, stack_b);
			rb(stack_b);
			if (end < size -1)
				end++;
			if (start < end)
				start++;
		}
		else if (ft_is_small(*stack_a, arr, end)) 
		{
			push_b(stack_a, stack_b);
			if (*stack_b && (*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
				sb(stack_b);
			if (end < size -1)
				end++;
			if (start < end)
				start++;
		}
		else
			ra(stack_a);
	}
	push_back_to_stack_a(stack_a, stack_b);
}

void	push_back_to_stack_a(t_node **stack_a, t_node **stack_b)
{
	int	max_position;

	while (*stack_b)
        {
		max_position = find_max_value(*stack_a);
                if (max_position <= ft_lstsize(*stack_b) / 2)
                {
                        while (max_position > 0)
                        {
                                rb(stack_b);
                                max_position--;
                        }
                }
                else
                {
                        while (max_position < ft_lstsize(*stack_b))
                        {
                                rrb(stack_b);
                                max_position++;
                        }

                }
		push_a(stack_b, stack_a);
    }

}
